#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    ll a[25];
    ll sum=0;
    ll ans=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll sum1;
    for(ll i=1;i<=((1<<n)-1);i++)
    {
        sum1=0;
        for(ll j=0;j<n;j++)
        {
            if(i&(1<<j))
                sum1+=a[j];
        }
        ans=min(ans,abs(sum-2*sum1));
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