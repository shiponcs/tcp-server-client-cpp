#include "TCP_socket.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

TCPSocketSpace::TCPSocket::TCPSocket() {
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd == -1) {
    std::cout << "Socket creation failed\n";
  }
}

TCPSocketSpace::TCPSocket::~TCPSocket() {
  if (sock_fd != -1) {
    close(sock_fd);
  }
}

int TCPSocketSpace::TCPSocket::get_socket_fd() { return sock_fd; }

int TCPSocketSpace::TCPSocketServer::receive(
    TCPSocketSpace::TCPSocket &client) {
  char buffer[1024] = {0};
  memset(buffer, 0, 1024);
  int receive_len = recv(client.sock_fd, buffer, 1024, 0);
  if (receive_len == -1) {
    std::cout << "can't read\n";
  } else {
    std::cout << buffer << std::endl;
  }
}

int TCPSocketSpace::TCPSocket::send(const char *msg) {
  return ::send(sock_fd, msg, strlen(msg), MSG_NOSIGNAL);
}

int TCPSocketSpace::TCPSocketServer::send(const char *msg, TCPSocket &client) {
  return ::write(client.sock_fd, msg, strlen(msg));
}

int TCPSocketSpace::TCPSocketServer::bind(int port) {
  socket_address.sin_family = AF_INET;
  socket_address.sin_addr.s_addr = INADDR_ANY;
  socket_address.sin_port = htons(port);
  return ::bind(sock_fd, (sockaddr *)&socket_address, sizeof(socket_address));
}

int TCPSocketSpace::TCPSocketServer::listen() { return ::listen(sock_fd, 10); }

int TCPSocketSpace::TCPSocketServer::accept(TCPSocket &client) {
  int addr_len = sizeof(client.socket_address);
  client.sock_fd = ::accept(sock_fd, (sockaddr *)&client.socket_address,
                            (socklen_t *)&addr_len);
  return client.sock_fd;
}

int TCPSocketSpace::TCPSocketClient::connet(const char domain[], int port) {
  socket_address.sin_family = AF_INET;
  socket_address.sin_port = htons(port);
  hostent *server = gethostbyname((char *)domain);
  bcopy((char *)server->h_addr, (char *)&socket_address.sin_addr.s_addr,
        server->h_length);
  return ::connect(sock_fd, (sockaddr *)&socket_address,
                   sizeof(socket_address));
  ;
}

int TCPSocketSpace::TCPSocket::receive() {
  char buffer[3000] = {0};
  memset(buffer, 0, 1024);
  int receive_len = read(sock_fd, buffer, 3000);
  if (receive_len == -1) {
    std::cout << "can't read\n";
  } else {
    std::cout << buffer << std::endl;
  }
}