#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool comp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}
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
    sort(v.begin(),v.end(),comp);
    //std::sort(v. begin(), v. end(), boost::bind(&std::pair<int, int>::second, _1) < boost::bind(&std::pair<int, int>::second, _2));
    int ans=1;
    //int maxans=0;
    int tmp=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(tmp<=v[i].first)
        {
            tmp=v[i].second;
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}