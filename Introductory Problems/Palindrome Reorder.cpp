#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
void solve()
{
   string str;
   cin>>str;
   ll a[26]={0};
   ll l=str.length();
   for(int i=0;i<l;i++)
   {
       a[str[i]-'A']++;
   }
   ll count=0;
   for(int i=0;i<26;i++)
   {
       if(a[i]>0&&a[i]%2!=0)
       {
           count++;
       }
   }
   if(count>=2)
   {
       cout<<"NO SOLUTION"<<endl;
       return;
   }
   char c;
   for(int i=0;i<26;i++)
   {
       if(a[i]>0&&a[i]%2==0)
       {
           for(int j=0;j<a[i]/2;j++)
           {
            char ch=char(i+'A');
            cout<<ch;
           }
       }
       else if(a[i]>0&&a[i]%2!=0)
       {
           c=char(i+'A');
           for(int j=0;j<a[i]/2;j++)
           {
            char ch=char(i+'A');
            cout<<ch;
           }
       }
   }
   if(count==1)
   cout<<c;
    for(int i=25;i>=0;i--)
   {
       if(a[i]>0&&a[i]%2==0)
       {
           //cout<<1<<endl;
           for(int j=0;j<a[i]/2;j++)
           {
            char ch=char(i+'A');
            cout<<ch;
           // cout<<5<<" ";
           }
       }
       else if(a[i]>0&&a[i]%2!=0)
       {
           //cout<<1<<endl;
           for(int j=0;j<a[i]/2;j++)
           {
            char ch=char(i+'A');
            cout<<ch;
           }
       }
   }
}
int main()
{
   ll t=1;
   //cin>>t;
   while(t--)
    solve();
}