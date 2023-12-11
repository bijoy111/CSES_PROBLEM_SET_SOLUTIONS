#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],n1[maxn];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        n1[i]=i-1;
        while(~n1[i]&&(a[n1[i]]>=a[i]))
        {
            n1[i]=n1[n1[i]];
        }
        cout<<n1[i]+1<<" ";
    }
}