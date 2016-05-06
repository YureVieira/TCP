#include "tcpclient.h"
#include <iostream>
using namespace std;

TcpClient::TcpClient()
{
    if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 )
        Error( const_cast<char *>( "error opening socket") );
}

void TcpClient::Connect(char* ip, int port)
{
    portno = port;

    if ( ( server = gethostbyname( ip ) ) == NULL )
        Error( const_cast<char *>("ERROR, no such host\n") );

    bzero( (char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy( (char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if ( connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        Error( const_cast<char *>( "ERROR connecting") );
}

int TcpClient::sendData(char *buffer, int size)
{
    if (write(newsockfd, buffer, size) < 0 )
    {
      Error( const_cast<char *>( "error writing to socket") );
      return -1;
    }
    return 0;
}

int TcpClient::getData(char *buffer, int size)
{
    for(int i=0;i<size;i++)
    {
        buffer[i]=0;
    }
    if ( read(newsockfd,buffer,size)  < 0 )
    {
        Error( const_cast<char *>( "error reading from socket") );
        return -1;
    }
    return 0;
}

void TcpClient::Close()
{
    close(newsockfd);
}

void TcpClient::Error(char *msg) {
    perror(msg);
//    exit(0);
}
