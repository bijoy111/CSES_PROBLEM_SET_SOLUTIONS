#include<bits/stdc++.h>
using namespace std;
int n,m;
//vector<int>ans;
//int *parent=new int[100005];
map<int,list<int>>edge;
//int pos=0;
class graph
{
    int v;
 
public:
    graph(int v)
    {
        this->v=v;
 
    }
    void addedge(int u,int v)
    {
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int dfs(int v,int color[],int col)
    {
        color[v]=col;
        list<int>nbd=edge[v];
        list<int>::iterator i;
        for(i=nbd.begin();i!=nbd.end();i++)
        {
            if(color[*i]==0)
            {
 
                dfs(*i,color,3-col);
            }
            if(color[v]==color[*i])
            {
                return 0;
            }
        }
        return 1;
    }
    /*void bfs(int v,int color[])
    {
        queue<int>q;
        q.push(v);
        color[v]=1;
        parent[v]=0;
        while(!q.empty())
        {
            int vtx=q.front();
            list<int>nbd=edge[vtx];
            q.pop();
            if(vtx==n)
            {
                pos=1;
                while(parent[vtx]!=0)
                {
                    ans.push_back(vtx);
                    vtx=parent[vtx];
                }
                ans.push_back(vtx);
                while(!q.empty())
                {
                    q.pop();
                }
            }
            else {
                list<int>::iterator i;
                for (i = nbd.begin(); i != nbd.end(); i++) {
                    if (color[*i] == 0) {
                        parent[*i] = vtx;
                        color[*i] = 1;
                        q.push(*i);
                    }
                }
            }
        }
    }*/
};
int main()
{
    cin>>n>>m;
    graph g(n+1);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g.addedge(x,y);
    }
    int *color=new int[n+1];
    for(int i=1;i<=n;i++)
        color[i]=0;
    //g.bfs(1,color);
    int var=1;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            int a=g.dfs(i,color,1);
            if(a==0)
            {
                var=0;
            }
        }
        else
        {
            list<int>nbd=edge[i];
            list<int>::iterator j;
            for (j = nbd.begin(); j != nbd.end(); j++) {
                if(color[*j]==color[i])
                {
                    var=0;
                }
            }
        }
    }
    //int var=g.dfs(1,color,1);
    if(var==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
            cout<<color[i]<<" ";
    }
    return 0;
}