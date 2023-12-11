#include<bits/stdc++.h>
using namespace std;
int n,m;
class graph
{
    int v;
    map<int,list<int>>edge;
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
    void dfs(int v,int color[])
    {
        color[v]=1;
        list<int> nbd=edge[v];
        list<int>::iterator i;
        for(i=nbd.begin();i!=nbd.end();i++)
        {
            if(color[*i]==0)
            {
                dfs(*i,color);
            }
        }
    }
 
};
int main()
{
 
    cin>>n>>m;
    graph g(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    int* color=new int[n+1];
    for(int i=1;i<=n;i++)
        color[i]=0;
    int road=-1;
    int *ans=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            road++;
            ans[road]=i;
            g.dfs(i,color);
 
        }
    }
    cout<<road<<endl;
    for(int i=1;i<=road;i++)
    {
        cout<<ans[i]<<" "<<ans[0]<<endl;
    }
    return 0;
}