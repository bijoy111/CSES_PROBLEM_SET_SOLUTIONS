#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}