#include<bits/stdc++.h>

using namespace std;

int Bin_search(int a[], int n, int x)
{
    int l = 0;
    int r = n-1;

    int m;

    while(l <= r)
    {
        m = (l+r)/2;

        if(a[m] == x) return m;

        if(a[m] < x) l = m + 1;

        if(a[m] > x) r = m - 1;
    }

    return -1;
}

int main()
{
    int a[1000];
    int num;
    int cnt = 0;
    for(int i=0;;i++)
    {
        int inp;
        cin>>inp;

        if(inp < 0)
            break;

        a[i] = inp;
        cnt++;
    }
    cin>>num;

    cout<<Bin_search(a, cnt, num);

    return 0;
}