//SPOJ - KQUERY

#include<bits/stdc++.h>
#define MAX 100007
using namespace std;

vector<int>t[4*MAX];
int in[MAX];

void build(int n,int l,int r)
{
    if(l==r)
    {
        t[n].push_back(in[l]);
        return;
    }
    int mid=(l+r)/2;
    build(n*2,l,mid);
    build(n*2+1,mid+1,r);
    merge(t[n*2].begin(),t[n*2].end(),t[n*2+1].begin(),t[n*2+1].end(),back_inserter(t[n]));
}

int query(int node,int l,int r,int i,int j,int k)
{
    if(l>j || r<i)return 0;
    if(l>=i && r<=j)
    {
        int pos=upper_bound(t[node].begin(),t[node].end(),k)-t[node].begin();
        return t[node].size()-pos;
    }
    int mid=(l+r)/2;
    return query(node*2,l,mid,i,j,k)+query(node*2+1,mid+1,r,i,j,k);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,l,r,q,ans;
    cin >> n;
    for(i=0; i<n; i++)cin >> in[i+1];
    build(1,1,n);
    cin >> q;
    for(i=0; i<q; i++)
    {
        cin >> l >> r >> k;
        ans=query(1,1,n,l,r,k);
        cout << ans << "\n";
    }

    return 0;
}
