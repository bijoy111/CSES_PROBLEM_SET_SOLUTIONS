#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int MOD=1e9+7;
void solve()
{
   int k,n;
   cin>>k>>n;
   int coin[N];
   int pos[N];
   pos[0]=1;
   for(int i=1;i<=k;i++)
   {
       cin>>coin[i];
   }
   int way[N];
   way[0]=1;
   for(int i=1;i<=n;i++)
    way[i]=0;
   for(int j=1;j<=k;j++)
   {
       for(int i=1;i<=n;i++)
       {
           if(i>=coin[j]&&pos[i-coin[j]])
           {
               pos[i]=1;
               way[i]+=way[i-coin[j]];
                way[i]%=MOD;
           }
       }
   }
  cout<<way[n]<<endl;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
