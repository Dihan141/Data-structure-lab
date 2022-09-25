#include<iostream>
#include<queue>

using namespace std;

class Stack
{
public:
    queue<int> que1;

    void push(int x) {
        //push into queue1
        que1.push(x);
    }

    int pop() {
        //declare a new queue
        queue<int> que2;
        //copy queue1 to queue2 until last element of queue1 remains
        while(que1.size()>1)
        {
            que2.push(que1.front());
            que1.pop();
        }
        //temporarily store last element in x
        int x = que1.front();
        //pop the last element
        que1.pop();
        //again store queue2 in queue1
        que1 = que2;
        //return that last element
        return x;
    }

    int top() {
        //return last element of queue1
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};

int main()
{
    Stack stck;
    stck.push(1);
    stck.push(2);
    stck.push(3);
    stck.push(4);

    while(!stck.empty())
    {
        cout<<stck.top()<<endl;
        stck.pop();
    }
}
