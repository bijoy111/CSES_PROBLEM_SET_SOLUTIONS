#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    ll sum=(n*(n+1)/2);
    if(sum%2!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    multiset<ll>m;
    multiset<ll>part1;
    for(int i=1;i<=n;i++)
        m.insert(i);
    ll ans=0;
    sum=sum/2;
    for(int i=n;i>=1;i--)
    {
        if(m.find(sum-ans)!=m.end())
        {
            part1.insert(sum-ans);
            m.erase(m.find(sum-ans));
            break;
        }
        m.erase(m.find(i));
        part1.insert(i);
        ans+=i;
    }
    cout<<"YES"<<endl;
    cout<<m.size()<<endl;
    for(auto x:m)
        cout<<x<<" ";
    cout<<endl;
    cout<<part1.size()<<endl;
    for(auto x:part1)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
   ll t=1;
   //cin>>t;
   while(t--)
    solve();
}