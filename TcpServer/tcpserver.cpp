#include "tcpserver.h"

TcpServer::TcpServer(int port)
{
    portno = port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error( const_cast<char *>("ERROR opening socket") );
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons( portno );
}

int TcpServer::init()
{
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
    {
        error( const_cast<char *>( "ERROR on binding" ) );
        return 0;
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    return 1;
}

int TcpServer::Conneted()
{
    if ( ( newsockfd = accept( sockfd, (struct sockaddr *) &cli_addr, (socklen_t*) &clilen) ) < 0 )
    {
        error( const_cast<char *>("ERROR on accept") );
        return 0;
    }
    return 1;
}

int TcpServer::sendData(char* buffer,int size)
{
    if (write(newsockfd, buffer, size) < 0 )
    {
      error( const_cast<char *>( "ERROR writing to socket") );
      return 0;
    }
    return 1;
}

int TcpServer::getData(char* buffer,int size)
{
    for(int i=0;i<size;i++)
    {
        buffer[i]=0;
    }
    if ( read(newsockfd,buffer,size)  < 0 )
    {
        error( const_cast<char *>( "ERROR reading from socket") );
        return 0;
    }
    return 1;
}

void TcpServer::Close()
{
    close(newsockfd);
}

void TcpServer::error(char *msg)
{
    perror(msg);
}
