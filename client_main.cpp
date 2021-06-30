#include "TCP_socket.hpp"
#include <iostream>

int main()
{
  TCPSocketSpace::TCPSocketClient client_socket;
  client_socket.connet("36.255.68.139", 5222);
    client_socket.send("<?xml version='1.0'?> <stream:stream to='ckotha.com' xmlns='jabber:client' xmlns:stream='http://etherx.jabber.org/streams' version='1.0'>");
    client_socket.receive();
    client_socket.receive();
    std::cout << "******************\n";
    client_socket.send("<iq type='set' id='auth2'><query xmlns='jabber:iq:auth'><username>matin1</username><password>safeai</password><resource>jingle</resource></query></iq>");
    client_socket.receive(); 
    // client_socket.send("<message from='matin1@ckotha.com' to='matin2@ckotha.com' xml:lang='en'>");
    // client_socket.send("<body>Hello</body>");
    // client_socket.send("</message>");
    client_socket.receive();
    client_socket.receive();
    client_socket.receive();
    // client_socket.send("</stream:stream>");
  // char buffer[1024] = {0};
  // client_socket.send(buffer);

  return 0;
}
