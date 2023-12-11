#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
int m = 1000000007;
void solve()
{
    ll n;
    cin>>n;
    ll ans=1;//(pow(2,n));
    for(int i=1;i<=n;i++)
    {
        ans=(2*ans)%m;
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