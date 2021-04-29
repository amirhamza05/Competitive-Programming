//lightoj - 1087

#include<bits/stdc++.h>
#define MAX 500007
using namespace std;
typedef long long ll;

int in[MAX],tree[4*MAX];

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=(in[l]==-1)?0:1;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void add(int node,int l,int r,int i,int val)
{
    if(l>i || r<i)return;
    if(l==r && i==l)
    {
        in[l]=val;
        tree[node]=1;
        return;
    }
    int mid=(l+r)/2;

    add(node*2,l,mid,i,val);
    add(node*2+1,mid+1,r,i,val);

    tree[node]=tree[node*2]+tree[node*2+1];
}

void del(int node,int l,int r,int k)
{
    if(l==r)
    {
        in[l]=-1;
        tree[node]=0;
        return;
    }
    int mid=(l+r)/2;
    if(tree[node*2]>=k)
        del(node*2,l,mid,k);
    else
        del(node*2+1,mid+1,r,k-tree[node*2]);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node,int l,int r,int k)
{
    if(l==r)
    {
        return in[l];
    }
    int mid=(l+r)/2;
    if(tree[node*2]>=k)
        return query(node*2,l,mid,k);
    else
        return query(node*2+1,mid+1,r,k-tree[node*2]);
}

void solve()
{

    int n,q,i,a,l,ans;
    char ty;
    memset(in,-1,sizeof(in));
    scanf("%d%d",&n,&q);
    for(i=1; i<=n; i++)scanf("%d",&in[i]);
    l=n;
    n=n+q+10;
    build(1,1,n);
    for(i=0; i<q; i++)
    {
        scanf(" %c%d",&ty,&a);
        if(ty=='a')add(1,1,n,++l,a);
        else
        {
            ans=query(1,1,n,a);
            if(ans==-1)printf("none\n");
            else printf("%d\n",ans);
            del(1,1,n,a);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,i;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        printf("Case %d:\n", i+1);
        solve();
    }


    return 0;
}
