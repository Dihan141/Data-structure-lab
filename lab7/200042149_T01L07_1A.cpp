#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

void AddNum(int num)
{
    if(pq2.empty())
        pq2.push(num);
    else
    {
        if(num > pq2.top())
            pq2.push(num);
        else
            pq1.push(num);

        int x = pq1.size();
        int y = pq2.size();
        
        if(y - x > 1)
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
        else if(x - y > 1)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
}

void FindMedian()
{
    if(pq1.size() == pq2.size())
        cout<<(pq1.top() + pq2.top())/2.0f<<endl;
    else if(pq1.size() > pq2.size())
        cout<<pq1.top()<<endl;
    else if(pq1.size() < pq2.size())
        cout<<pq2.top()<<endl;
}


int main()
{
    cout<<"1.AddNumber()"<<endl;
    cout<<"2.FindMedian()"<<endl;

    while(1)
    {
        int n;
        cin>>n;

        switch (n)
        {
        case 1:
            int x;
            cin>>x;
            AddNum(x);
            break;
        case 2:
            FindMedian();
            break;
        
        default:
            break;
        }
    }
    return 0;
}