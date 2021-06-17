#include "TCP_socket.hpp"
#include <iostream>

int main() {
  TCPSocketSpace::TCPSocketClient client_socket;
  client_socket.connet("157.230.41.161", 33333);
  client_socket.send("I'm in\n");
  client_socket.receive();
  char buffer[1024] = {0};
  client_socket.send(buffer);

  return 0;
}
