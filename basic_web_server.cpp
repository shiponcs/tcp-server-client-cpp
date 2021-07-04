#include "TCP_socket.hpp"
#include <iostream>

int main()
{
  TCPSocketSpace::TCPSocketServer serverSocket;
  TCPSocketSpace::TCPSocket client;
  if (serverSocket.bind(33333) == -1)
  {
    std::cout << "Binding failed\n";
  }
  while (true)
  {

    if (serverSocket.listen() == -1)
    {
      std::cout << "Listening failed\n";
    }

    if (serverSocket.accept(client) == -1)
    {
      std::cout << "acceptancing failed\n";
    }
    serverSocket.receive(client);
    char buffer[] = "HTTP/1.1 200 OK\r\n"
                    "Connection: close\r\n"
                    "Content-type: text/html\r\n"
                    "\r\n"
                    "<html>\r\n"
                    "<head>\r\n"
                    "<title>Welcome</title>\r\n"
                    "</head>\r\n"
                    "<body>\r\n"
                    "<h1>Welcome to the world's simplest webserver by <i>matin<i></h1>\r\n"
                    "</body>\r\n"
                    "</html>\r\n\r\n";
    serverSocket.send(buffer, client);
    close(client.sock_fd);
  }

  return 0;
}