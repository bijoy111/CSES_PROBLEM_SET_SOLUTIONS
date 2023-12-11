#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve()
{
    int n;
    cin>>n;
    int a[N];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]=i;
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<a[i-1])
            ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}