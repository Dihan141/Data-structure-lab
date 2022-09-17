#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>> pq;

    for(int i=0; i<n; i++)
    {
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }

    //iterate until one element remains
    while(pq.size()>1)
    {
        //store top element in a variable, then pop
        int t = pq.top();
        pq.pop();
        //if first top element is equal second top element then pop again
        //else push first element - second element, then pop the top element
        if(pq.top() == t)
        {
            pq.pop();
        }
        else
        {
            pq.push(t-pq.top());
            pq.pop();
        }
    }

    //if queue is empty then all stones are crushed, print 0
    //else, there is a stone remaining, print the top element
    if(pq.empty())
        cout<<"0"<<endl;
    else
        cout<<pq.top()<<endl;
    return 0;
}