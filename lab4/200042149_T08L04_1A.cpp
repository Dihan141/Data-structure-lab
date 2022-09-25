#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<int> plyrs;
    int n, k;
    cin>>n>>k;

    for(int i=0; i<n; i++)
    {
        plyrs.push(i+1);
    }

    int cnt = 0;
    while(plyrs.size() != 1)
    {
        //count number of moves
        cnt++;
        //if cnt gets equal to K pop the player and set count to zero
        if(cnt == k)
        {
            plyrs.pop();
            cnt = 0;
        }
        else
        {
            //else pop the first player then insert him at the end
            int tmp = plyrs.front();
            plyrs.pop();
            plyrs.push(tmp);
        }
    }

    cout<<plyrs.front()<<endl;
    return 0;
}
