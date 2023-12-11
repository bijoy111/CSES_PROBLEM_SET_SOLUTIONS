#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    int r=0;
    int time=0;
    for(int i=0;i<n;i++)
    {
        time+=v[i].first;
        r+=(v[i].second-time);
    }
    cout<<r<<endl;
}
signed main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}