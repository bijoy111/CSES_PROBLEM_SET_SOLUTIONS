#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
//int m = 1000000007;
void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=5;i<=n;i*=5)
    {
            ans+=(n/i);
    }
    cout<<ans<<endl;
}
int main()
{
   ll t=1;
   //cin>>t;
   while(t--)
    solve();
}
