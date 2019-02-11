
/**
 *    Topic:   Number Theory
 *    Author:  Sk.Amir Hamza
 *    Created: 10.08.2018
**/

#include<bits/stdc++.h>
#define MOD 1000000007
#define MAX 100007
using namespace std;

typedef long long ll;

ll fac[MAX],flag[MAX];
vector<ll>prime;

struct number_theory
{

    number_theory();
    ll bigmod(ll n,ll k);
    ll modinv(ll n);
    ll nPr(ll n,ll p);
    ll nCr(ll n,ll p);
    ll mod_number(ll num,ll mod=MOD);
    void sieve();
    vector<ll>divisors_list(ll n);

};

void number_theory::sieve()
{
    ll n=MAX-5,i,j;
    for(i=4; i<n; i+=2)flag[i]=1;
    flag[1]=1;
    prime.push_back(2);
    for(i=3; i<n; i+=2)
    {
        if(flag[i]==0)
        {
            prime.push_back(i);
            if(i<=sqrt(n))
            {
                for(j=i*i; j<n; j+=i*2)flag[j]=1;
            }
        }
    }
}

number_theory::number_theory()
{
    fac[0]=1;
    for(int i=1; i<=MAX-5; i++)
        fac[i]=((fac[i-1]%MOD)*i)%MOD;
    this->sieve();
}


vector<ll>number_theory::divisors_list(ll n)
{

    vector<ll>res;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                res.push_back(i);
            else
            {
                res.push_back(i);
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}


ll number_theory::bigmod(ll n,ll k)
{
    if(k==0)return 1;
    ll x=bigmod(n,k>>1);
    x=(x*x)%MOD;
    return (k&1)?(x*n)%MOD:(x)%MOD;
}

ll number_theory::modinv(ll n)
{
    return bigmod(n,MOD-2);
}

ll number_theory::nPr(ll n,ll p)
{
    return ((fac[n]%MOD)*(modinv(fac[p])%MOD))%MOD;
}

ll number_theory::nCr(ll n,ll p)
{
    return ((nPr(n,p)%MOD)*modinv(fac[n-p])%MOD)%MOD;
}

ll number_theory::mod_number(ll num,ll mod)
{
    return (num % mod + mod) % mod;
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    number_theory ntheory;
    ll n=2,t,i,m,k=454,res;
    res=ntheory.bigmod(n,k);
    vector<ll>v=ntheory.divisors_list(24);
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> n >> m >> k;
        res=(n<k)?0:((ntheory.bigmod(m,k)%MOD)*(ntheory.nCr(n,k))%MOD)%MOD;
        cout << res << "\n";
    }

    return 0;
}
