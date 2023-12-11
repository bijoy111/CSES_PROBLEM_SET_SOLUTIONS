#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>vec[100001];
 
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,edg;
        cin>>u>>v>>edg;
        vec[u].emplace_back(edg,v);
    }
    //int s,d;
    //cin>>s>>d;
    int * cost=new int[n+1];
    int * visited=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cost[i]=9223372036854775807;
        visited[i]=0;
    }
    cost[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({cost[1],1});
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int vertex=p.second;
        if(visited[vertex]==1)
            continue;
        visited[vertex]=1;
        for(int i=0;i<vec[vertex].size();i++)
        {
            int adj=vec[vertex][i].second;
            int x=vec[vertex][i].first;
            if(visited[adj]==0&&(cost[vertex]+x)<cost[adj])
            {
                cost[adj]=cost[vertex]+x;
                pq.push({cost[adj],adj});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<cost[i]<<" ";
    }
}