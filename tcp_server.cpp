#include "TCP_socket.hpp"
#include <iostream>

int main() {
  TCPSocketSpace::TCPSocketServer serverSocket;
  TCPSocketSpace::TCPSocket client;
  if (serverSocket.bind(33333) == -1) {
    std::cout << "Binding failed\n";
  }

  if (serverSocket.listen() == -1) {
    std::cout << "Listening failed\n";
  }

  if (serverSocket.accept(client) == -1) {
    std::cout << "acceptancing failed\n";
  }
  serverSocket.receive(client);
  char buffer[1024] = {0};
  std::cin >> buffer;
  serverSocket.send(buffer, client);

  return 0;
} 