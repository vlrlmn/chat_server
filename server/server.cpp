#include "server.hpp"

void handle_new_connection(Socket server, std::vector<Socket> &clients, std::vector<pollfd> &poll_fds) {
    Socket client = server.accept();
    std::cout << "New client connected" << std::endl;

    struct pollfd pfd;
    pfd.fd = client.getFd();
    pfd.events = POLLIN;
    poll_fds.push_back(pfd);
    clients.push_back(std::move(client));
}

void disconnect_client(size_t index, std::vector<Socket> &clients, std::vector<pollfd> &poll_fds) {
    close(poll_fds[index].fd);
    poll_fds.erase(poll_fds.begin() + index);
    clients.erase(clients.begin() + index - 1);
}

void handle_client_message(size_t index, std::vector<Socket> &clients, std::vector<pollfd> &poll_fds) {
    Socket &client = clients[index - 1];
    std::string message;
    ssize_t recieved = client.recieve(message);
    if (recieved < 0)
        disconnect_client(index, clients, poll_fds);
    else {
        for (size_t j = 0; j < clients.size(); ++j) {
            if (j != index - 1) {
                clients[j].send("Client: " + message);
            }
        }
    }
}

int main(int argc, char **argv) {

    if (argc != 2) 
    {
        std::cerr << "Usage: ./server <port>" << std::endl;
        exit(1);
    }

    Socket server;

    int port = std::stoi(argv[1]);

    if(!server.bind(port)) {
        std::cerr << "Error binding socket to the port" << std::endl;
    }
    if (!server.listen(10)) {
        std::cerr << "Error settling socket listenin" << std::endl;
    }

    std::vector<struct pollfd> poll_fds;
    std::vector<Socket> clients;

    struct pollfd server_poll;
    server_poll.fd = server.getFd();
    server_poll.events = POLLIN;
    poll_fds.push_back(server_poll);
    while (true) {
        int ret = poll(poll_fds.data(), poll_fds.size(), -1);
        if (ret < 0)
        {
            perror("Poll error");
            break ;
        }
        for (size_t i = 0; i < poll_fds.size(); i++) {
            if (poll_fds[i].revents & POLLIN) {
                if (poll_fds[i].fd == server.getFd()) {
                    handle_new_connection(server, clients, poll_fds);
                } else {
                    handle_client_message(i, clients, poll_fds);
                }
            }
        }
    }
}