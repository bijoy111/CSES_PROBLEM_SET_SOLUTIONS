#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int ans=1;
    map<int,int>m;
    for(int i=0,j=0;i<n;i++)
    {
        while(j<n&&m[v[j]]<1)
        {
            m[v[j]]++;
            j++;
        }
        ans=max(ans,j-i);
        m[v[i]]--;
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}