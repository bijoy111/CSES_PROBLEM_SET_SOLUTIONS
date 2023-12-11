#include <bits/stdc++.h>
using namespace std;
vector<char>v;
int visited[1001][1001];
char maze[1001][1001];
char parent[1001][1001];
int dist[1001][1001];
int b=0;
int n,m;
void bfs(int i,int j)
{
    int distan[1001][1001];
    for(int t3=1;t3<=n;t3++)
    {
        for(int t4=1;t4<=m;t4++)
        {
            distan[t3][t4]=INT_MAX;
        }
    }
    queue<pair<int,int>>q;
    q.push({i,j});
    parent[i][j]='S';
    distan[i][j]=0;
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
            if ((x-1)>=1&&visited[x - 1][y] == 0&&(1+distan[x][y])<dist[x-1][y]) {
                visited[x - 1][y] = 1;
                q.push({x - 1, y});
                parent[x-1][y]='D';
                distan[x-1][y]=1+distan[x][y];
                //cout<<i-1<<" "<<j<<endl;
            }
            if ((x+1)<=n&&visited[x + 1][y] == 0&&(1+distan[x][y])<dist[x+1][y]) {
                visited[x+1][y]=1;
                q.push({x+1,y});
                parent[x+1][y]='U';
                distan[x+1][y]=1+distan[x][y];
                //cout<<i+1<<" "<<j<<endl;
            }
            if ((y-1)>=1&&visited[x][y - 1] == 0&&(1+distan[x][y])<dist[x][y-1]) {
                visited[x][y-1]=1;
                q.push({x,y-1});
                parent[x][y-1]='R';
                distan[x][y-1]=1+distan[x][y];
                //cout<<i<<" "<<j-1<<endl;
            }
            if ((y+1)<=m&&visited[x][y + 1] == 0&&(1+distan[x][y])<dist[x][y+1]) {
                visited[x][y+1]=1;
                q.push({x,y+1});
                parent[x][y+1]='L';
                distan[x][y+1]=1+distan[x][y];
                //cout<<i<<" "<<j+1<<endl;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    queue<vector<int>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            visited[i][j]=0;
            dist[i][j]=INT_MAX;
        }
    }
    int t1,t2;
    int corner=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='#'||maze[i][j]=='M')
            {
                visited[i][j]=1;
            }
            else if(maze[i][j]=='A')
            {
                if(i==1||i==n||j==1||j==m)
                    corner=1;
                t1=i,t2=j;
            }
            if(maze[i][j]!='#'&&maze[i][j]!='M'&&maze[i][j]!='A'&&(i==1||i==n||j==1||j==m))
            {
                maze[i][j]='B';
            }
        }
    }
    if(corner)
    {
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maze[i][j]=='M')
            {
                q.push({i,j,0});
            }
        }
    }
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();
        int x=curr[0];
        int y=curr[1];
        int step=curr[2];
        if(x<0||x>n||y<0||y>m||maze[x][y]=='#'||dist[x][y]!=INT_MAX)
        {
            continue;
        }
        dist[x][y]=step;
        q.push({x+1,y,1+step});
        q.push({x-1,y,1+step});
        q.push({x,y+1,1+step});
        q.push({x,y-1,1+step});
    }
    bfs(t1,t2);
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
    return 0;
}