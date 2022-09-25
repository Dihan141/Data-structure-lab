#include<iostream>
#include<queue>

using namespace std;

queue<int> que;

int ping(int t)
{
    que.push(t);
    //basically we update the request and deletes the timed out requests
    while(que.front() < (t-3000))
    {
        que.pop();
    }
    //queue size is the number of requests within time limit
    return que.size();
}

int main()
{
    cout<<ping(1)<<endl;
    cout<<ping(2)<<endl;
    cout<<ping(3)<<endl;
    cout<<ping(4)<<endl;
    cout<<ping(3001)<<endl;
    cout<<ping(3002)<<endl;
    cout<<ping(3003)<<endl;
    cout<<ping(6003)<<endl;
    cout<<ping(10003)<<endl;
    return 0;
}
