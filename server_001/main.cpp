#include <stdio.h>
#include <iostream>
#include <../TcpServer/tcpserver.h>
#include <arpa/inet.h>
using namespace std;


int main(int argc, char *argv[])
{    
    TcpServer server(10000);
    server.init();

    for(;;)
    {
        cout<<"waiting for new client..."<<endl;
        server.Conneted();
                //cout<<"opened new communication with client"<<endl;
                char msg[20];
            server.getData(msg,sizeof(msg));
            printf("IP address is: %s\n", inet_ntoa(server.cli_addr.sin_addr));
            printf("port is: %d\n", (int) ntohs(server.cli_addr.sin_port));
            cout<<"Message:\n"<<msg<<endl;
    }
    server.Close();
    return 0;
}
