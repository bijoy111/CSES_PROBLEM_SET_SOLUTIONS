#include<bits/stdc++.h>
#include<math.h>
using namespace std;
const int N=2e5+5;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[N],b[N];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int j=0;
    int ans=0;
    for(int i=0;i<n&&j<m;)
    {
        //cout<<a[i]<<" "<<b[j]<<endl;
        if(abs(a[i]-b[j])<=k)
        {
            ans++;
            i++,j++;
        }
        else if(a[i]<b[j])
            i++;
        else
            j++;
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}