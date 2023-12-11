#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e5+5;
void solve()
{
   int n;
   cin>>n;
   int a[N];
   for(int i=0;i<n;i++)
    cin>>a[i];
   multiset<int>m;
   m.insert(a[0]);
   for(int i=1;i<n;i++)
   {
       auto x=m.upper_bound(a[i]);
       if(x!=m.end())
       {
           m.erase(x);
           m.insert(a[i]);
       }
       else
       {
           m.insert(a[i]);
       }
   }
   cout<<m.size()<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}