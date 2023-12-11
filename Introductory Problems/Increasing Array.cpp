#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
int main()
{
   ll n;
   cin>>n;
   vector<ll>v;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       v.push_back(x);
   }
   ll moves=0;
   for(int i=1;i<n;i++)
   {
       if(v[i]<v[i-1])
       {
           moves+=(v[i-1]-v[i]);
           v[i]=v[i-1];
       }
   }
   cout<<moves<<endl;
   return 0;
}