#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,x;
    cin>>n>>x;
    multiset<ll>m;
    for(int i=0;i<n;i++)
    {
        ll y;
        cin>>y;
        m.insert(y);
    }
    ll weight_left=x;
    ll ans=1;
    ll children=0;
    while(!(m.empty()))
    {
        auto z=m.upper_bound(weight_left);
        if(z==m.begin()||children==2)
        {
            weight_left=x;
            ans++;
            children=0;
        }
        else
        {
            z--;
            weight_left-=*z;
            m.erase(m.find(*z));
            children++;
        }
    }
    cout<<ans<<endl;
    m.clear();
}
int main()
{
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
}
