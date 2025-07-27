#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

#define SOCKET_ERROR 1
class Socket {
    private:
        int sockfd;
    public:
        Socket();
        explicit Socket(int fd);
        ~Socket();
        int bind(int port);
        bool listen(int backlog);
        Socket accept();
        bool connect(const std::string &ip, int port);
        ssize_t send(const std::string& data);
        ssize_t recieve(std::string& out);
        void close();
        int getFd() const;
};

#endif