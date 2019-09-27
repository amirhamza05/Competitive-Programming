#include<bits/stdc++.h>
#define MAX 200007
using namespace std;
typedef long long ll;

struct LCA
{

    vector<ll>height,eular,first,tree;
    vector<bool>visit;
    vector<vector<ll> >adj;
    ll n;
    LCA(vector<vector<ll> >ad)
    {
        adj=ad;
        n=adj.size();
        height.resize(n);
        first.resize(n);
        eular.reserve(n*2);
        visit.assign(n,false);
        dfs(1);
        ll m=eular.size();
        tree.resize(m*4);
        build(1,0,m-1);
    }

    void dfs(ll s,ll h=0)
    {
        if(visit[s])
            return;
        visit[s]=1;
        height[s]=h;
        first[s]=eular.size();
        eular.push_back(s);
        for(ll i=0; i<adj[s].size(); i++)
        {
            if(visit[adj[s][i]]==1)
                continue;
            dfs(adj[s][i],h+1);
            eular.push_back(s);
        }
    }

    void build(ll node,ll l,ll r)
    {
        if(l==r)
        {
            tree[node]=eular[l];
            return;
        }
        ll mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        tree[node]=(height[tree[node*2]]<height[tree[node*2+1]])?tree[node*2]:tree[node*2+1];
    }

    ll query(ll node,ll l,ll r,ll i,ll j)
    {
        if(l>j || r<i)
            return -1;
        if(l>=i && r<=j)
            return tree[node];
        ll mid=(l+r)/2;
        ll left=query(node*2,l,mid,i,j);
        ll right=query(node*2+1,mid+1,r,i,j);
        if(left==-1)
            return right;
        if(right==-1)
            return left;
        return height[left]<height[right]?left:right;
    }

    ll lca(ll u,ll v)
    {
        ll l=first[u],r=first[v];
        if(l>r)
            swap(l,r);
        return query(1,0,eular.size()-1,l,r);
    }
};

int main()
{



    return 0;
}

