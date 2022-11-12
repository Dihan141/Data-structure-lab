#include<bits/stdc++.h>

using namespace std;

bool substringCheck(int b[], int m, unordered_map<int, int> umap)
{
    for(int i=0; i<m; i++)
    {
        if(umap[b[i]] == 0) return false;
    }
    return true;
}

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

    int m;
    int b[m];
    cin>>m;
    for(int i=0; i<m; i++)
        cin>>b[i];

    if(substringCheck(b, m, umap)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}