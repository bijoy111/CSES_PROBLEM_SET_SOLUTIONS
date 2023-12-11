#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
   string str;
   cin>>str;
   sort(str.begin(),str.end());
   vector<string>v;
   do
   {
       v.push_back(str);
   }while(next_permutation(str.begin(),str.end()));
   cout<<v.size()<<endl;
   for(string s:v)
    cout<<s<<endl;
   return;
}
int main()
{
   ll t=1;
   //cin>>t;
   while(t--)
    solve();
}