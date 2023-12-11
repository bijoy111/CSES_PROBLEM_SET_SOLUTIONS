#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
void solve()
{
   ll a,b;
   cin>>a>>b;
   if((a+b)%3!=0)
   {
       cout<<"NO"<<endl;
       return;
   }
   ll mi=min(a,b);
   ll ma=max(a,b);
   if(ma>(mi*2))
   {
       cout<<"NO"<<endl;
       return;
   }
   cout<<"YES"<<endl;
}
int main()
{
   ll t;
   cin>>t;
   while(t--)
    solve();
}