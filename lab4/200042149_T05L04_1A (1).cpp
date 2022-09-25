#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    queue<pair<int,int>> que;
    vector<int> v;
    int k;
    while(1)
    {
        int x;
        cin>>x;
        if(x == -1) break;

        v.push_back(x);
    }
    cin>>k;

    for(int i=0; i<v.size(); i++)
    {
        //make pair of value and index and push in queue
        que.push(make_pair(v[i], i));
    }

    //keep count of seconds
    int cnt = 0;
    while(!que.empty())
    {
        int f = (que.front()).first;
        int s = (que.front()).second;
        //decrement the top person's ticket number
        f--;
        cnt++;

        if(f==0)
        {
            //if ticket number of top person is zero and index of that person equals k
            //print the count and break
            if(s == k)
            {
                cout<<cnt<<endl;
                break;
            }
            else
            {
                //else pop that person
                que.pop();
            }
        }
        else
        {
            //if ticket number not zero
            //then push the person and remaining tickets to buy in the end
            //then pop the person from top
            que.push(make_pair(f,s));
            que.pop();
        }
    }
    return 0;
}
