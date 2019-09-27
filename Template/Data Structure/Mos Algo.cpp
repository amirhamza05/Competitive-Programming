#include<bits/stdc++.h>
#define MAX 200007
using namespace std;
typedef long long ll;

ll s,in[MAX],mp[1000007],res[MAX],ans=0;
struct str
{
    ll l,r,i;
};

bool operator<(str a,str b)
{
    if(a.l/s==b.l/s)
        return a.r<b.r;
    return (a.l/s<b.l/s);
}

void add(ll i)
{
    ll val=in[i];
    ans-=(mp[val]*mp[val]*val);
    mp[val]++;
    ans+=(mp[val]*mp[val]*val);
}

void del(ll i)
{
    ll val=in[i];
    ans-=(mp[val]*mp[val]*val);
    mp[val]--;
    ans+=(mp[val]*mp[val]*val);
}

void mos_algo(vector<str>v)
{
    ll i,l=1,r=0,l1=1,r1=0,pos;
    sort(v.begin(),v.end());
    for(i=0; i<v.size(); i++)
    {
        l1=v[i].l,r1=v[i].r,pos=v[i].i;
        while(l>l1)add(--l);
        while(r<r1)add(++r);
        while(l<l1)del(l++);
        while(r>r1)del(r--);
        res[pos]=ans;
    }
}


int main()
{

    ll n,q,i,a,l,r;
    vector<str>v;
    scanf("%I64d%I64d",&n,&q);
    s=sqrt(n)+1;
    for(i=0; i<n; i++)
        scanf("%I64d",&in[i+1]);
    for(i=0; i<q; i++)
    {
        scanf("%I64d%I64d",&l,&r);
        v.push_back({l,r,i+1});
    }
    mos_algo(v);
    for(i=1; i<=q; i++)
    {
        printf("%I64d\n",res[i]);
    }

    return 0;
}
