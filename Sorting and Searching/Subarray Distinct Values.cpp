#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[N];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int left=0;
    map<int,int>map;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        //if(map.find(a[i])==map.end())
            //map[a[i]]=0;
        map[a[i]]++;
        while(map.size()>k)
        {
            map[a[left]]--;
            if(map[a[left]]==0)
            {
                map.erase(a[left]);
            }
                left++;
        }
        ans+=(i-left+1);
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