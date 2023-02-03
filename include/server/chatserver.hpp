#ifndef CHATSERVER_H
#define CHATSERVER_H

#endif
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<iostream>
#include<functional>
#include<string>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;
class ChatServer
{
    public:
     ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg   );
    void start();
    
    private:
    void onConnection(const TcpConnectionPtr &conn);
     void onMessage(const TcpConnectionPtr &conn,
                            Buffer *buffer,
                            Timestamp time);
    TcpServer _server;
    EventLoop *_loop;
};