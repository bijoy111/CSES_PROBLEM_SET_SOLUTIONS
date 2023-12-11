#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int x,n;
    cin>>x>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    set<int>s;
    s.insert(0);
    s.insert(x);
    multiset<int>m;
    m.insert(x);
    for(int i=0;i<n;i++)
    {
        auto x=s.upper_bound(v[i]);
        int y=*x;
        x--;
        int z=*x;
        m.erase(m.find(y-z));
        m.insert(y-v[i]);
        m.insert(v[i]-z);
        auto b=m.end();
        b--;
        cout<<*b<<" ";
        s.insert(v[i]);
    }
    cout<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}