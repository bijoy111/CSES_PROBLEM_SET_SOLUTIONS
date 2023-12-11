#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
void solve()
{
   int n,x;
   cin>>n>>x;
   int price[N];
   int pages[N];
   for(int i=1;i<=n;i++)
   {
       cin>>price[i];
   }
    for(int i=1;i<=n;i++)
   {
       cin>>pages[i];
   }
   int dp[N];
   for(int i=0;i<=x;i++)
    dp[i]=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=x;j>=0;j--)
       {
           if(j>=price[i])
           dp[j]=max(dp[j],pages[i]+dp[j-price[i]]);
       }
   }
   cout<<dp[x]<<endl;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}