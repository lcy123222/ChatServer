#include "chatserver.hpp"
#include"chatservice.hpp"
#include<functional>

#include"json.hpp"
using namespace std;
using namespace placeholders;
using json=nlohmann::json;
 ChatServer::ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg   )
            :_server(loop,listenAddr,nameArg),_loop(loop)
            {
              
              _server.setConnectionCallback(bind(&ChatServer::onConnection,this,_1));
              _server.setMessageCallback(bind(&ChatServer::onMessage,this,_1,_2,_3));
              _server.setThreadNum(4);
            }
void ChatServer::onConnection(const TcpConnectionPtr &conn){
         if(!conn->connected())
         { 
            ChatService::instance()->clientCloseException(conn);
            conn->shutdown();
         }
         
    }
    void ChatServer::onMessage(const TcpConnectionPtr &conn,
                            Buffer *buffer,
                            Timestamp time)
    {
       string buf=buffer->retrieveAllAsString();
      //  cout<<"buf: "<<buf<<endl;
       json js=json::parse(buf);
      cout<<"recv data:"<<buf<<"time"<<time.toString()<<endl;
      //  conn->send(buf);
      auto msgHandler=ChatService::instance()->getHandler(js["msgid"].get<int>());

      msgHandler(conn,js,time);
    }
void ChatServer::start()
    {
     _server.start();
    }