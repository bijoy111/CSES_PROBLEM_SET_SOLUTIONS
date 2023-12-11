#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve()
{
    int n,m;
    cin>>n>>m;
    multiset<int>tt;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        tt.insert(y);
    }
    int a[N];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        auto z=tt.upper_bound(a[i]);
        if(z==tt.begin())
        {
            cout<<-1<<endl;
        }
        else
        {
            z--;
            cout<<*z<<endl;
            tt.erase(tt.find(*z));
        }
    }
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}