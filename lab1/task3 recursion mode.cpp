#include<bits/stdc++.h>

using namespace std;

int Bin_search(int a[], int l, int r, int x)
{
    int mid = (l + r)/2;

    if (l > r) return -1;

    if(a[mid] == x) return mid;

    if(a[mid] < x) return Bin_search(a, mid + 1, r, x);

    if(a[mid] > x) return Bin_search(a, l, mid-1, x);
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

    int left = 0;
    int right = cnt-1;

    cout<<Bin_search(a, left, right, num);

    return 0;
}
