#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin>>n;
    while(n!=1)
    {
        cout<<n<<" ";
        if(n%2!=0)
        {
            n=n*3+1;
            //cout<<n<<" ";
        }
        else
        {
            n/=2;
            //cout<<n<<" ";
        }
    }
    cout<<n<<endl;
}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}