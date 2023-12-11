#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+5;
const int X=1e6+5;
const int mod=1e9+7;
void solve()
{
    int n,x;
    cin>>n>>x;
    int way[X]={0};
    way[0]=1;
    int a[N];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=x;i++)
    {
        for(int j=1;a[j]<=i&&j<=n;j++)
        {
            way[i]+=way[i-a[j]];
        }
        way[i]=way[i]%mod;
    }
    cout<<way[x]%mod<<endl;
    return;
}
signed main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}