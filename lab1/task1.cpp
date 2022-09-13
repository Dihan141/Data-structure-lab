#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> num;
    map<int, int> mp;

    for(int i=0;;i++)
    {
        int inp;
        cin>>inp;

        if(inp <= 0)
            break;

        num.push_back(inp);
    }

    for(int i=0; i<num.size(); i++)
    {
        mp[num[i]]++;
    }
    
    auto i = mp.begin();
    vector<pair<int, int>> n;

    while(i != mp.end())
    {
        n.push_back(make_pair(i->second, i->first));
        i++;
    }

    sort(n.begin(), n.end(), greater<>());
    for(int i=0; i<n.size(); i++)
    {
        cout<<n[i].second<<" occurs: "<<n[i].first<<" times"<<endl;
    }
    return 0;
}