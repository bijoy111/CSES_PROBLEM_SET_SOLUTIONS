#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin>>n;
    multiset<int>m;
    int x;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        m.insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(m.find(i)==m.end())
        {
            cout<<i<<endl;
            m.clear();
            return;
        }
    }
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}