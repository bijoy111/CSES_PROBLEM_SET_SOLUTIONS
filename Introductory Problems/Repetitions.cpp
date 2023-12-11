#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
int main()
{
   string str;
   cin>>str;
   ll l=str.length();
   ll ans=1;
   ll tmp=1;
   for(int i=1;i<l;i++)
   {
       if(str[i]==str[i-1])
       {
           tmp++;
       }
       else
       {
           ans=max(ans,tmp);
           tmp=1;
       }
   }
   ans=max(ans,tmp);
   cout<<ans<<endl;
   return 0;
}