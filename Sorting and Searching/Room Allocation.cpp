#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
void solve()
{
    int n;
    cin>>n;
    int ans[N];
    array<int,3>a[N];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][1]>>a[i][0];
        a[i][2]=i;
    }
    sort(a,a+n);
    set<array<int,2>>s;
    for(int i=0;i<n;i++)
    {
        auto it=s.lower_bound({a[i][1]});
        if(it!=s.begin())
        {
            it--;
            ans[a[i][2]]=(*it)[1];
            s.erase(it);
        }
        else
        {
            ans[a[i][2]]=s.size();
        }
            s.insert({a[i][0],ans[a[i][2]]});
    }
    cout<<s.size()<<endl;
    for(int i=0;i<n;i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}