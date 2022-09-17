#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    //greater<int> for ascending order
    priority_queue<int, vector<int>, greater<int>> pq;
    

    for(int i=0; i<n; i++)
    {
        int tmp;
        cin>>tmp;

        pq.push(tmp);
    }

    int cnt = 0;
    while(pq.top() < k)
    {
        // the equation was: 1*least sweet + 2*second least sweet
        //storing first top element in a variable, then pop
        int t;
        t = pq.top();
        pq.pop();
        // add 2x of second top element to the variable
        // pop the top element
        // push the variable in queue
        t += 2 * pq.top();
        pq.pop();
        pq.push(t);
        // keep count of steps
        cnt++;
    }

    cout<<cnt<<endl;
    return 0;
}