#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
void solve()
{
    int n;
    cin>>n;
    int a[N];
    for(int i=0;i<n;i++)
        cin>>a[i];
    set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i])==s.end())
        {
            s.insert(a[i]);
            auto it=s.find(a[i]);
            it++;
            if(it!=s.end())
                s.erase(*it);
        }
    }
    cout<<s.size()<<endl;
}
signed main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}