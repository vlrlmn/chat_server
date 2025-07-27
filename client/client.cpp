#include "client.hpp"

int main(int argc, char **argv) {

    if (argc != 2) 
    {
        std::cerr << "Usage: ./server <port>" << std::endl;
        exit(1);
    }

    int port = std::stoi(argv[1]);

    Socket client;

    if (!client.connect("127.0.0.1", port)) {
        std::cerr << "Error connecting client" << std::endl;
    }
}