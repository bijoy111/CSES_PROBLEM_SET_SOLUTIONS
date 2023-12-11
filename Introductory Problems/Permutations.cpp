#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
int main()
{
   ll n;
   cin>>n;
   if(n==2||n==3)
   {
       cout<<"NO SOLUTION"<<endl;
       return 0;
   }
   else if(n==1)
   {
       cout<<1<<endl;
       return 0;
   }
   else if(n%2==0)
   {
       for(int i=2;i<=n;i+=2)
        cout<<i<<" ";
       for(int i=1;i<n;i+=2)
        cout<<i<<" ";
       cout<<endl;
       return 0;
   }
   else if(n%2!=0)
   {
      for(int i=1;i<=n;i+=2)
        cout<<i<<" ";
    for(int i=2;i<n;i+=2)
        cout<<i<<" ";
       cout<<endl;
       return 0;
   }
}