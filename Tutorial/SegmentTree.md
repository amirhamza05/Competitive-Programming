# Segment Tree

### KGSS - Maximum Sum
- **Link:** https://www.spoj.com/problems/KGSS/
- **Algorithm:** Segment tree, Pair Segment Tree

> Firstly store all value
<details>
  <summary>Code</summary>
  
  ```c++
#include<bits/stdc++.h>
#define MAX 100007
using namespace std;
typedef long long ll;

pair<int,int>tree[4*MAX];
int in[MAX];

pair<int,int>cmp(pair<int,int>a,pair<int,int>b) {
    vector<int>v;
    v.push_back(a.first);
    v.push_back(a.second);
    v.push_back(b.first);
    v.push_back(b.second);
    sort(v.begin(),v.end(),greater<int>());
    return {v[0],v[1]};
}

void build(int node,int l,int r) {
    if(l == r) {
        tree[node] = {in[l],-1};
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node] = cmp(tree[node*2],tree[node*2+1]);
}

void update(int node,int l,int r,int i,int val) {
    if(l>i || r<i)return;
    if(l == r && l == i) {
        tree[node] = {val,-1};
        return;
    }
    int mid = (l+r)/2;
    update(node*2,l,mid,i,val);
    update(node*2+1,mid+1,r,i,val);
    tree[node] = cmp(tree[node*2],tree[node*2+1]);
}

pair<int,int>query(int node,int l,int r,int i,int j) {
    if(l>j || r<i)return {-1,-1};
    if(l >= i && r <=j)return tree[node];
    int mid = (l+r)/2;
    return cmp(query(node>>1,l,mid,i,j),query(node>>1|1,mid+1,r,i,j));
}

int main() {
    int test=4,t,i,n,q,l,r;
    char type;
    cin >> n;
    for(i=1; i<=n; i++)cin >> in[i];
    build(1,1,n);
    cin >> q;
    for(i=0; i<q; i++) {
        cin >> type >> l >> r;
        if(type == 'Q') {
            pair<int,int>get = query(1,1,n,l,r);
            cout << (get.first+get.second) << "\n";
        } else update(1,1,n,l,r);
    }

    return 0;
}

```
</details> 


