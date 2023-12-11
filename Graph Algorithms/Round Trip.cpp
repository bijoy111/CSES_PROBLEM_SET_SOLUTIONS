#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int * parent=new int[100005];
class Graph {
    int v;
    map<int, list<int> > edge;
public:
    Graph(int v);
    void addEdge(int src, int dest);
    int DFS(int v,int color[]);
    bool iscyclic();
};
 
// Initialize graph
Graph::Graph(int v)
{
    this->v=v;
}
 
// Add edges
void Graph::addEdge(int src, int dest) {
    edge[src].push_back(dest);
    edge[dest].push_back(src);
}
 
// DFS algorithm
int Graph::DFS(int v,int color[]) {
    //cout<<v<<endl;
    color[v]=1;
    list<int> adjList = edge[v];
 
    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
    {
        //cout<<v<<endl;
        //parent[*i]=v;
        if(color[*i]==1&&parent[v]!=*i)
        {
            int p=v;
            int tmp=1;
            //cout<<parent[5]<<endl;
            while(parent[p]!=(*i))
            {
                tmp++;
                p=parent[p];
            }
            tmp++;
            //cout<<tmp<<endl;
            if(tmp>=2)
            {
 
                p=v;
                //cout<<p<<endl;
                ans.push_back(*i);
                while(parent[p]!=(*i))
                {
                    ans.push_back(p);
                    p=parent[p];
                    //cout<<p<<endl;
                }
                ans.push_back(p);
                ans.push_back(*i);
            }
            return 1;
        }
        if(color[*i]==0)
        {
            parent[*i]=v;
            if(DFS(*i,color)==1)
            return 1;
        }
    }
    color[v]=2;
    //ans.push_back(v);
    return 0;
}
bool Graph:: iscyclic()
{
    int *color=new int [v+1];
    for(int i=1;i<=v;i++)
    {
        color[i]=0;
    }
    for(int i=1;i<=v;i++)
    {
        if(color[i]==0)
        {
            if(DFS(i,color)==1)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int n,m;
    cin>>n>>m;
 
    Graph g(n+5);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
 
 
    if(g.iscyclic())
    {
        cout<<ans.size()<<endl;
        for(int j=ans.size()-1;j>=0;j--)
        {
            cout<<ans[j]<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
 
    }
 
    return 0;
}