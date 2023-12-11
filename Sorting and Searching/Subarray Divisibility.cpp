#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
//#define int long long
void solve()
{
    long long n;
    cin>>n;
    long long a[N];
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long ans=0;
    map<long long,long long>m;
    m[0]++;
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        sum+=a[i];
        m[((sum%n)+n)%n]++;
        ans+=(m[((sum%n)+n)%n]-1);
    }
    cout<<ans<<endl;
}
int main()
{
   long long t=1;
    while(t--)
        solve();
    return 0;
}