#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>vec[100001];
vector<pair<int,int>>vecrev[100001];
vector<vector<int>>ve;
int n,m;
int *cost1;
int *cost2;
int *visited;
void dijkstra(int s,int d)
{
    for(int i=1;i<=n;i++)
    {
        cost1[i]=9223372036854775807;
        visited[i]=0;
    }
    cost1[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({cost1[s],s});
    while(!pq.empty())//n times
    {
        pair<int,int>p=pq.top();
        pq.pop();//O(log n)
        int vertex=p.second;
        if(visited[vertex]==1)
            continue;
        visited[vertex]=1;
        for(int i=0;i<vec[vertex].size();i++)// m/n times
        {
            int adj=vec[vertex][i].second;
            if(visited[adj]==0&&(cost1[vertex]+vec[vertex][i].first)<cost1[adj])
            {
                cost1[adj]=cost1[vertex]+vec[vertex][i].first;
                pq.push({cost1[adj],adj});
            }
        }
    }
}
void dijkstra2(int s,int d)
{
    for(int i=1;i<=n;i++)
    {
        cost2[i]=9223372036854775807;
        visited[i]=0;
    }
    cost2[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({cost2[s],s});
    while(!pq.empty())//n times
    {
        pair<int,int>p=pq.top();
        pq.pop();//O(log n)
        int vertex=p.second;
        if(visited[vertex]==1)
            continue;
        visited[vertex]=1;
        for(int i=0;i<vecrev[vertex].size();i++)// m/n times
        {
            int adj=vecrev[vertex][i].second;
            if(visited[adj]==0&&(cost2[vertex]+vecrev[vertex][i].first)<cost2[adj])
            {
                cost2[adj]=cost2[vertex]+vecrev[vertex][i].first;
                pq.push({cost2[adj],adj});
            }
        }
    }
}
signed main()
{
 
    cin>>n>>m;
    cost1=new int[n+1];
    cost2=new int[n+1];
    visited=new int[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,edg;
        cin>>u>>v>>edg;
        vec[u].push_back({edg,v});
        vecrev[v].push_back({edg,u});
        ve.push_back({u,v,edg});
    }
    dijkstra(1,n);
    dijkstra2(n,1);
    int ans=9223372036854775807;
    for(auto x:ve)
    {
        int tmp=cost1[x[0]]+cost2[x[1]]+(x[2]/2);
        if(ans>tmp&&tmp>0)
        {
            ans=tmp;
        }
    }
    cout<<ans<<endl;
}