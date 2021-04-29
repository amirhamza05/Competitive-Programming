//lightoj - 1164


#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
int lzy[4*MAX],rangeVal[4*MAX];
long long tree[4*MAX];

void build(int node, int l, int r)
{
    rangeVal[node] = (r-l+1);
    lzy[node] = 0;
    tree[node] = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
}
void pushVal(int node,int val)
{
    lzy[node] += val;
    tree[node] += (rangeVal[node]*val);
}
void pushLzy(int node)
{
    pushVal(node*2,lzy[node]);
    pushVal(node*2+1,lzy[node]);
    lzy[node] = 0;
}

void update(int node,int l,int r,int i,int j,int v)
{
    if(l>j || r<i)return;
    if(l>=i && r<=j)
    {
        pushVal(node,v);
        return;
    }
    pushLzy(node);
    int mid = (l+r)/2;
    update(node*2,l,mid,i,j,v);
    update(node*2+1,mid+1,r,i,j,v);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long query(int node,int l,int r,int i,int j)
{
    if(l>j || r<i)return 0;
    if(l>=i && r<=j)return tree[node];
    pushLzy(node);
    int mid = (l+r)/2;
    return query(node*2,l,mid,i,j)+query(node*2+1,mid+1,r,i,j);
}


void solve(int t)
{
    int n,i,q,per,l,r,v;
    scanf("%d%d",&n,&q);
    n--;
    build(1,0,n);
    printf("Case %d:\n",t);
    for(i=0; i<q; i++)
    {
        scanf("%d%d%d",&per,&l,&r);
        if(!per)
        {
            scanf("%d",&v);
            update(1,0,n,l,r,v);
        }
        else
        {
            long long ans = query(1,0,n,l,r);
            printf("%lld\n",ans);
        }
    }
}

int main()
{

    int t,i;
    scanf("%d",&t);
    for(i=0; i<t; i++)solve(i+1);

    return 0;
}
