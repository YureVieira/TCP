#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

class TcpServer
{
public:
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    TcpServer(int port);
    int init();
    int Conneted();
    int sendData(char *buffer, int size );
    int getData(char *buffer, int size);
    void Close();
private:
    int sockfd;
    int newsockfd;
    int portno;
    int clilen;
    void error( char *msg );

};

#endif // TCPSERVER_H
