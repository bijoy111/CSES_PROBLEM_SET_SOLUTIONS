#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int mod=1e9+7;
void solve()
{
    int n;
    cin>>n;
    int way[N]={0};
    way[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i&&j<=6;j++)
        {
            way[i]+=way[i-j];
        }
        way[i]=way[i]%mod;
    }
    cout<<way[n]%mod<<endl;
    return;
}
signed main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}