#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
void solve()
{
    int n,x;
    cin>>n>>x;
    map<int,int>mp;
    int ans=0;
    int a[N];
    int s=0;
    mp[0]++;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
 
        //if(s>=x)
        ans+=mp[s-x];
         mp[s]++;
    }
    cout<<ans<<endl;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}