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
    sort(a,a+n);
    int ans=1;
    for(int i=0;i<n&&a[i]<=ans;i++)
    {
        ans+=a[i];
    }
    cout<<ans<<endl;
    return;
}
signed main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}