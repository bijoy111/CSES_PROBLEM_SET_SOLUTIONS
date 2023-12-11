#include<bits/stdc++.h>
using namespace std;
#define int long long
int cross(int a[],int l,int m,int r)
{
    int i=m,j=m+1;
    int l_sum=a[i];
    int r_sum=a[j];
    int sum=0;
    while(i>=l)
    {
        sum+=a[i];
        if(sum>l_sum)
        {
            l_sum=sum;
        }
        i--;
    }
    sum=0;
    while(j<=r)
    {
        sum+=a[j];
        if(sum>r_sum)
        {
            r_sum=sum;
        }
        j++;
    }
    return l_sum+r_sum;
}
int fun(int a[],int l,int r)
{
    if(l==r)
    {
        return a[l];
    }
    else
    {
        int mid=(l+r)/2;
        int t1=fun(a,l,mid);
        int t2=fun(a,mid+1,r);
        int t3=cross(a,l,mid,r);
        return max(max(t1,t2),t3);
    }
}
signed main()
{
    int n;
    cin>>n;
    int * a=new int[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<fun(a,0,n-1)<<endl;
    return 0;
}