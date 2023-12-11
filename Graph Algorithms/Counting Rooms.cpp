#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m;
char v[N][N];
int vis[N][N];
void dfs(int i,int j)
{
    if(i-1>=0&&vis[i-1][j]==0)
    {
        vis[i-1][j]=1;
        dfs(i-1,j);
    }
    if(i+1<n&&vis[i+1][j]==0)
    {
        vis[i+1][j]=1;
        dfs(i+1,j);
    }
    if(j-1>=0&&vis[i][j-1]==0)
    {
        vis[i][j-1]=1;
        dfs(i,j-1);
    }
    if(j+1<m&&vis[i][j+1]==0)
    {
        vis[i][j+1]=1;
        dfs(i,j+1);
    }
}
int main()
{
 
    cin>>n>>m;
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char x;
            cin>>x;
            if(x=='.')
            {
                vis[i][j]=0;
            }
            else
            {
                vis[i][j]=1;
            }
            v[i][j]=x;
        }
    }
    int room=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j]==0)
            {
                room++;
                dfs(i,j);
            }
        }
    }
    cout<<room<<endl;
    return 0;
}