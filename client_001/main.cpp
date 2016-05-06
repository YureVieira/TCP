#include <../TcpClient/tcpclient.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char serverIp[]="192.168.1.2";
    TcpClient client;
    client.Connect(serverIp, 10000);
    char msg[] = "Hello World!";
    for(int i=0;i<10;i++)
    {
//        sprintf(msg,"%d",i);
        cout<<sizeof(msg)<<endl;
        client.sendData(msg,sizeof(msg));
        sleep(1);
    }
    client.Close();
    return 0;
}
