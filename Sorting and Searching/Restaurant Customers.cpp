#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve()
{
    int n;
    cin>>n;
    vector<int>a;
    vector<int>l;
    vector<int>all;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        l.push_back(y);
        all.push_back(x);
        all.push_back(y);
    }
    sort(a.begin(),a.end());
    sort(l.begin(),l.end());
    sort(all.begin(),all.end());
    int i=0,j=0;
    int ans=0,maxans=0;
    for(int x:all)
    {
        if(x==a[i])
        {
            ans++;
            maxans=max(maxans,ans);
            i++;
        }
        else if(x==l[j])
        {
            ans--;
            j++;
        }
    }
    cout<<maxans<<endl;
}
int main()
{
    int t=1;
    while(t--)
        solve();
    return 0;
}