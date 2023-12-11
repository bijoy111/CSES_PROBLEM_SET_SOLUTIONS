#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve()
{
    int n,x;
    cin>>n>>x;
    //vector<pair<int,int>>v;
    map<int,int>ma;
    multiset<int>m;
    int a[N];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        //v.push_back({a[i],i+1});
        ma[a[i]]=i+1;
        m.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        m.erase(m.find(a[i]));
        if(m.find(x-a[i])!=m.end())
        {
            cout<<i+1<<" "<<ma[x-a[i]]<<endl;
            return;
        }
        m.insert(a[i]);
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}