#include<iostream>

using namespace std;

class CircularQueue{
private:
    int n = 5;
    int Front = -1;
    int Rear = -1;
    int cqueue[5];
public:
    void Enqueue(int val)
    {
        //if front in first index and rear in last index, that means queue is full
        if((Front == 0 && Rear == n-1))
        {
            cout<<"Overflow occured."<<endl;
            return;
        }
        //if front is -1 that means queue is emty and we have to initialize front and rear value to first index
        if(Front == -1)
        {
            Front = 0;
            Rear = 0;
        }
        else
        {
            //if rear is at the end then we set it in the first index of array, as it is circular queue
            //else increment rear
            if(Rear == n-1)
                Rear = 0;
            else
                Rear++;
        }
        //insert value in rear
        cqueue[Rear] = val;
    }

    void Dequeue()
    {
        //if front is -1 then queue is empty
        if(Front == -1)
        {
            cout<<"queue empty"<<endl;
            return;
        }
        //if front is equal to rear that means we are deleting the last element
        //so we set both front and rear value to -1, meaning the queue is empty again
        if(Front == Rear)
        {
            Front = -1;
            Rear = -1;
        }
        else
        {
            //if front is in last index we set it to first index again
            //else increment front
            if(Front == n-1)
                Front = 0;
            else
                Front++;
        }
    }

    int front()
    {
        //return the top element
        return cqueue[Front];
    }

    int rear()
    {
        //return the last element
        return cqueue[Rear];
    }

    bool isEmpty()
    {
        if(Front == -1 && Rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        //if the empty function is false then the full function is true and vice versa
        if(!isEmpty()) return true;
        else return false;
    }
};

int main()
{
    CircularQueue cq;
    //before pushing
    cout<<cq.isEmpty()<<endl;
    cout<<cq.isFull()<<endl;
    cout<<endl<<endl;

    //pushing values
    //Enqueue check
    cq.Enqueue(1);
    cq.Enqueue(2);
    cq.Enqueue(3);
    cq.Enqueue(4);
    cq.Enqueue(5);

    //front and rear value check
    cout<<cq.front()<<endl;
    cout<<cq.rear()<<endl;
    cout<<endl<<endl;

    //isFull and isEmpty check
    cout<<cq.isEmpty()<<endl;
    cout<<cq.isFull()<<endl;

    cout<<endl<<endl;
    //dequeue check
    cq.Dequeue();
    cq.Dequeue();
    cout<<cq.front()<<endl;
    return 0;
}
