#include "socket.hpp"

Socket::Socket() {
    sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("Socket not opened");
}

Socket::Socket(int fd) {
    sockfd = fd;
}

Socket::~Socket() {
    close();
}

int Socket::bind(int port) {
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    return ::bind(sockfd, (sockaddr*)&addr, sizeof(addr)) == 0;
}

bool Socket::listen(int backlog) {
    return ::listen(sockfd, backlog) == 0;
}

Socket Socket::accept() {
    int clientFd = ::accept(sockfd, nullptr, nullptr);
    return Socket(clientFd);
}

bool Socket::connect(const std::string &ip, int port) {
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    ::inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
    return ::connect(sockfd, (sockaddr* )&addr, sizeof(addr)) == 0;
}

ssize_t Socket::send(const std::string& data) {
    return ::send(sockfd, data.c_str(), data.size(), 0);
}

ssize_t Socket::recieve(std::string& out) {
    char buffer[1024] = {};
    ssize_t readLen = ::read(sockfd, buffer, out.size());
    if (readLen > 0) {
        out = std::string(buffer, readLen);
    }
    return readLen;
}

void Socket::close() {
    if (sockfd >= 0) {
        ::shutdown(sockfd, SHUT_RDWR);
        ::close(sockfd);
        sockfd = -1;
    }
}

int Socket::getFd() const {
    return this->sockfd;
}