#include<bits/stdc++.h>
using namespace std;
int Mod=1000000007;
int main()
{
    long long n;
    cin>>n;
    char grid[n+2][n+2];
    long long dp[n+2][n+2];
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>grid[i][j];
        }
    }
    if(grid[1][1]=='*')
        dp[1][1]=0;
    else
        dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1)
            {
                continue;
            }
            if(grid[i][j]=='*')
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%Mod;
            }
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}