#ifndef TCP_SOCKET_HPP
#define TCP_SOCKET_HPP

#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h> // data types used for system call
#include <unistd.h>

namespace TCPSocketSpace {
class TCPSocket {
public:
  TCPSocket();
  ~TCPSocket();
  int get_socket_fd();
  int send(const char *msg);
  int receive();
  int sock_fd;
  sockaddr_in socket_address;
};

class TCPSocketServer : public TCPSocket {
public:
  TCPSocketServer(){};
  // ~TCPSocketServer();

  int bind(int port);
  int listen();
  int accept(TCPSocket &clientSocket);

  int receive(TCPSocket &client);
  int send(const char *msg, TCPSocket &client);

private:
  int client_sock_fd;
};

class TCPSocketClient : public TCPSocket {
public:
  TCPSocketClient(){};
  int connet(const char *domain, int port);
};
} // namespace TCPSocketSpace

#endif