#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
void solve()
{
   int n;
   cin>>n;
   int dp[N];
   dp[0]=0;
   for(int i=1;i<=n;i++)
   {
       int tmp=i;
       int ms=INT_MAX;
       while(tmp!=0)
       {
           int di=tmp%10;
           tmp/=10;
           if(di!=0)
           ms=min(ms,1+dp[i-di]);
       }
       dp[i]=ms;
   }
   cout<<dp[n]<<endl;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}