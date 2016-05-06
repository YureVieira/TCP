#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

class TcpClient
{
public:
    struct sockaddr_in serv_addr;
    TcpClient();
    void Connect(char *ip, int port);
    int sendData(char *buffer, int size );
    int getData(char *buffer, int size);
    void Close();

private:
    int sockfd;
    int portno;
    int newsockfd;
    struct hostent *server;
    void Error(char *msg);
};

#endif // TCPCLIENT_H
