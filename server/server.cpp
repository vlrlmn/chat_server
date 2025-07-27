#include "server.hpp"


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

    Socket clinet = server.accept();
    std::cout << "Client connected!\n";

}