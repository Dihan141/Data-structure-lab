#include<iostream>
#include<queue>

using namespace std;

queue<int> stdnt;

int Solve(int sndwch[],int n)
{
    //iterate through the sandwich array
    for(int i=0; i<n; i++)
    {
        //keep track of the queue size after every iteration
        int sze = stdnt.size();
        //keep count of the students who didn't get sandwich
        int cnt = 0;
        while(1)
        {
            //if top student in the queue gets sandwich pop him
            if(stdnt.front() == sndwch[i])
            {
                stdnt.pop();
                break;
            }
            else
            {
                //else pop him from front and push him in the back
                //incremnent count
                int tmp = stdnt.front();
                stdnt.pop();
                stdnt.push(tmp);
                cnt++;
                //if count gets equal to queue size that means the same student has come back again
                //so he will get back in the line again
                //ultimately no one will get their favourite sandwich
                //return the count
                if(cnt == sze)
                    return cnt;
            }
        }
    }
    //return queue size
    return stdnt.size();
}

int main()
{

    int n;
    cin>>n;
    int a[n];
    int sndwch[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        stdnt.push(a[i]);
    }
    for(int i=0; i<n; i++)
    {
        cin>>sndwch[i];
    }

    cout<<Solve(sndwch, n)<<endl;

    return 0;
}
