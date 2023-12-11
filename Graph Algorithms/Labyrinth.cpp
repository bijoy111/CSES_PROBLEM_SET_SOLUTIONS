#include <bits/stdc++.h>
using namespace std;
vector<char>v;
bool vis[1001][1001];
char maze[1001][1001];
char parent[1001][1001];
int b=0;
int n,m;
void bfs(int i,int j)
{
    queue<pair<int,int>>q;
    q.push({i,j});
    parent[i][j]='S';
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        int x=p.first;
        int y=p.second;
        q.pop();
        if(maze[x][y]=='B')
        {
            b=1;
            while(maze[x][y]!='A')
            {
                if(parent[x][y]=='L')
                {
                    y--;
                    v.push_back('R');
                }
                else if(parent[x][y]=='R')
                {
                    y++;
                    v.push_back('L');
                }
                else if(parent[x][y]=='U')
                {
                    x--;
                    v.push_back('D');
                }
                else if(parent[x][y]=='D')
                {
                    x++;
                    v.push_back('U');
                }
            }
            while(!q.empty())
                q.pop();
        }
        else {
            if ((x-1)>=1&&vis[x - 1][y] == 0) {
                vis[x - 1][y] = 1;
                q.push({x - 1, y});
                parent[x-1][y]='D';
                //cout<<i-1<<" "<<j<<endl;
            }
            if ((x+1)<=n&&vis[x + 1][y] == 0) {
                vis[x+1][y]=1;
                q.push({x+1,y});
                parent[x+1][y]='U';
                //cout<<i+1<<" "<<j<<endl;
            }
            if ((y-1)>=1&&vis[x][y - 1] == 0) {
                vis[x][y-1]=1;
                q.push({x,y-1});
                parent[x][y-1]='R';
                //cout<<i<<" "<<j-1<<endl;
            }
            if ((y+1)<=m&&vis[x][y + 1] == 0) {
                vis[x][y+1]=1;
                q.push({x,y+1});
                parent[x][y+1]='L';
                //cout<<i<<" "<<j+1<<endl;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            vis[i][j]=0;
        }
    }
    //char maze[n][m];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='#')
            {
                vis[i][j] = 1;
            }
        }
    };
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maze[i][j]=='A')
            {
                bfs(i,j);
                if(b==1)
                {
                    cout<<"YES"<<endl;
                    cout<<v.size()<<endl;
                    for(int k=v.size()-1;k>=0;k--)
                    {
                        cout<<v[k];
                    }
                    cout<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}