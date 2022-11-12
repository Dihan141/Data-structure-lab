#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, int> umap;
    int n;
    int a[n];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        umap[a[i]]++;
    }

    int target;
    int f = 0;
    cin>>target;

    for(int i=0; i<n; i++)
    {
        if(umap[target - a[i]] != 0)
        {
            cout<<a[i]<<","<<target - a[i]<<endl;
            umap[a[i]] = 0;
            f = 1;
        }
    }

    if(f == 0) cout<<"No pair found"<<endl;
    return 0;
}