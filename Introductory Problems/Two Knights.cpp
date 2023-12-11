#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    for(ll k=1;k<=n;k++)
    {
        cout<<(((k*k)*((k*k)-1))/2)-(4*(k-1)*(k-2))<<endl;
    }
}
int main()
{
   ll t=1;
   //cin>>t;
   while(t--)
    solve();
}