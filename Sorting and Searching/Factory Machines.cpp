#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5+5;
void solve()
{
    int n,t;
    cin>>n>>t;
    int a[N];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
  int l=1,r=1e18;
  int ans=1e18;
  while(l<=r)
  {
      int mid=(l+r)/2;
      int s=0;
      for(int i=0;i<n;i++)
      {
          s+=min((mid/a[i]),(int)1e9);
      }
      if(s>=t)
      {
          ans=min(mid,ans);
          r=mid-1;
      }
      else
      {
          l=mid+1;
      }
  }
  cout<<ans<<endl;
}
signed main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}