#include<bits/stdc++.h>

using namespace std;

int Factorial(int n)
{
    if(n > 0) return n * Factorial(n-1);
    else return 1;
}

int main()
{
    int n;
    cin>>n;

    cout<<Factorial(n)<<endl;
    return 0;
}