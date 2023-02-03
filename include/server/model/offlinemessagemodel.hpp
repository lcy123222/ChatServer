#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include<list>
class OfflineMsgModel
{
    public:
    void insert(int userid,string msg);
    void remove(int userid);
    vector<string> query(int userid);

    private:
};
#endif 