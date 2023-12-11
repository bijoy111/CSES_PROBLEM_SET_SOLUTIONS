#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5+5;
void solve()
{
    int n;
    cin>>n;
    int a[N];
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    sort(a,a+n);
    cout<<max(s,a[n-1]*2);
}
signed main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}