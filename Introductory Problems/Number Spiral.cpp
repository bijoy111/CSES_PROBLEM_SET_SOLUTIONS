#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll r,c;
    cin>>r>>c;
    ll x=max(r,c);
    ll ma=x*x;
    ll mi=(x-1)*(x-1)+1;
    //cout<<ma<<" "<<mi;
    if(x%2==0)
    {
        if(r==x)
        {
            cout<<(x*x)-(c-1)<<endl;
            return;
        }
        else if(c==x)
        {
            cout<<((x-1)*(x-1)+1)+(r-1)<<endl;
            return;
        }
    }
    else
    {
        if(r==x)
        {
            cout<<((x-1)*(x-1)+1)+(c-1)<<endl;
            return;
        }
        else if(c==x)
        {
            cout<<(x*x)-(r-1)<<endl;
            return;
        }
    }
}
int main()
{
   ll t;
   cin>>t;
   while(t--)
    solve();
}