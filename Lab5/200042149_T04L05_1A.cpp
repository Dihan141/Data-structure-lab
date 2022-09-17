#include<bits/stdc++.h>

using namespace std;

void Sol()
{   
    int n;
    cin>>n;
    //two priority queue for start time and end time
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for(int i=0; i<n; i++)
    {
        int t1, t2;
        cin>>t1>>t2;
        pq1.push(t1);
        pq2.push(t2);
    }

    //ongoing meeting zero and room count one for calculation purpose
    int ongngMeetings = 0;
    int roomcnt = 1;

    //loop will go on until all start times are popped, meaning there is no meeting left to start
    while(!pq1.empty())
    {
        //if top element of pq1 is not greater or equal to top element of pq2 that means no meeting has ended yet
        //in that case, pop the start time and increment ongoing meeting count
        //else pop end time and decrement ongoing meeting variable
        if(pq1.top() < pq2.top())
        {
            pq1.pop();
            ongngMeetings++;

            //if ongoing meeting is greater than room count than increase room count by setting it equal to ongoing meeting
            if(ongngMeetings > roomcnt)
            {
                roomcnt = ongngMeetings;
            }
        }
        else
        {
            pq2.pop();
            ongngMeetings--;
        }
    }

    cout<<roomcnt<<endl;
}

int main()
{
    Sol();
    return 0;
}