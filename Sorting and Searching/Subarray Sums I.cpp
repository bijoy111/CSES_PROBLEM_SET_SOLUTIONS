#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve()
{
    int n,x;
    cin>>n>>x;
    int a[N];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int currsum=0;
    int left=0;
    int right=-1;
    int ans=0;
    while(right<n)
    {
        if(currsum==x)
        {
            ans++;
            right++;
            currsum+=a[right];
        }
        if(currsum<x)
        {
            right++;
            currsum+=a[right];
        }
        else if(currsum>x)
        {
            currsum-=a[left];
            left++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
}