#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
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
   int how[N];
   how[0]=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=k;j++)
       {
           if(i>=coin[j]&&pos[i-coin[j]])
           {
               if(pos[i]==0)
               {
                   pos[i]=1;
                   how[i]=how[i-coin[j]]+1;
               }
               else
               {
                   how[i]=min(how[i],how[i-coin[j]]+1);
               }
           }
       }
   }
   if(pos[n]==0)
   {
       cout<<-1<<endl;
       return;
   }
   cout<<how[n]<<endl;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}