#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
int **mat;
int **p;
const int N=9223372036854775807;
void print_path(int s,int d)
{
    if(p[s][d]!=0)
    {
        print_path(s,p[s][d]);
        cout<<p[s][d]<<"->";
        print_path(p[s][d],d);
        return;
    }
    else
        return;
}
signed main()
{
    cin>>n>>m>>q;
    mat=new int*[n+1];
    p=new int*[n+1];
    for(int i=1;i<=n;i++)
    {
        mat[i]=new int[n+1];
        p[i]=new int[n+1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j]=0;
            if(i==j)
            {
                mat[i][j]=0;
            }
            else
            {
                mat[i][j]=N;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,edg;
        cin>>u>>v>>edg;
        if(mat[u][v]>edg)
        mat[u][v]=edg;
        if(mat[v][u]>edg)
        mat[v][u]=edg;
    }
    for(int k=1;k<=n;k++)//n times
    {
        for(int i=1;i<=n;i++)//n times
        {
            for(int j=1;j<=n;j++)//n times
            {
                if(mat[i][k]!=N&&mat[k][j]!=N&&mat[i][j]>(mat[i][k] + mat[k][j]))
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                    p[i][j]=k;
                }
            }
        }
    }
 
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(mat[a][b]==N)
        {
            cout<<-1<<endl;
        }
        else
        cout<<mat[a][b]<<endl;
    }
    return 0;
}