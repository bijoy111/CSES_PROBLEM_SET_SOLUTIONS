#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,pair<int,int>>>edge;
//this class for dfs
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
signed main()
{
    int n,m;
    cin>>n>>m;
    graph g(n+1);//for dfs
    for(int i=0;i<m;i++)
    {
        int u,v,edg;
        cin>>u>>v>>edg;
        edg=edg*(-1);
        edge.push_back({edg,{u,v}});
        g.addedge(v,u);//for dfs
    }
    //this color array for dfs
    int* color=new int[n+1];
    for(int i=1;i<=n;i++)
        color[i]=0;
 
    int * cost=new int[n+1];
    int * parent=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cost[i]=9223372036854775807;
    }
    cost[1]=0;
    parent[1]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<edge.size();j++)
        {
            int ed=edge[j].first;
            int x=edge[j].second.first;
            int y=edge[j].second.second;
            if(cost[x]!=9223372036854775807&&cost[y]>(cost[x]+ed))
            {
                cost[y]=cost[x]+ed;
                parent[y]=x;
            }
        }
    }
    set<int>mul;
    for(int j=0;j<edge.size();j++)
    {
        int ed=edge[j].first;
        int x=edge[j].second.first;
        int y=edge[j].second.second;
        if(cost[x]!=9223372036854775807&&cost[y]>(cost[x]+ed))
        {
            cost[y]=cost[x]+ed;
            parent[y]=x;
            mul.insert(y);
        }
    }
    g.dfs(n,color);
    for(int i=1;i<=n;i++)
    {
        if(color[i]&&mul.count(i))
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<-cost[n]<<endl;
    return 0;
}