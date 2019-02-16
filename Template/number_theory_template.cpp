
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
typedef pair<ll,ll>pii;

ll fac[MAX],flag[MAX];
vector<ll>prime;

struct number_theory
{
    number_theory();

    ///number theory function
    void sieve();
    vector<ll>divisors_list(ll n);
    vector<ll>prime_factorization(ll n);
    ll sum_of_divisor(ll n);
    ll total_divisor(ll n);

    ///modulo arithmetic function
    ll bigmod(ll n,ll k);
    ll modinv(ll n);

    ///combinatorics function
    ll nPr(ll n,ll p);
    ll nCr(ll n,ll p);

    ///number process function
    ll big_mul(ll a,ll b,ll m);
    ll mod_number(ll num,ll mod=MOD);

};

number_theory::number_theory()
{
    fac[0]=1;
    for(int i=1; i<=MAX-5; i++)
        fac[i]=((fac[i-1]%MOD)*i)%MOD;
    this->sieve();
}

///start number theory function

void number_theory::sieve()
{
    ll n=MAX-5,i,j;
    flag[1]=1;
    for(i=4; i<n; i+=2)
        flag[i]=1;
    prime.push_back(2);
    for(i=3; i<n; i+=2)
    {
        if(flag[i]==0)
        {
            prime.push_back(i);
            if(i<=sqrt(n))
            {
                for(j=i*i; j<n; j+=i*2)
                    flag[j]=1;
            }
        }
    }
}

vector<ll>number_theory::divisors_list(ll n)
{
    vector<ll>res;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            res.push_back(i);
            if((n/i)!=i)
                res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

vector<ll>number_theory::prime_factorization(ll n)
{
    vector<ll>v;
    for(ll i=0; (prime[i]*prime[i])<=n; i++)
    {
        if(n==1)
            break;
        ll power=0;
        while(n%prime[i]==0)
            n/=prime[i],power++;;
        if(power>0)
            v.push_back(prime[i]);
    }
    if(n!=1)
        v.push_back(n);
    return v;
}

///start modulo arithmetic function

ll number_theory::bigmod(ll n,ll k)
{
    if(k==0)
        return 1;
    ll x=bigmod(n,k>>1);
    x=(x*x)%MOD;
    return (k&1)?(x*n)%MOD:(x)%MOD;
}

ll number_theory::modinv(ll n)
{
    return bigmod(n,MOD-2);
}

///start number process function

ll number_theory::big_mul(ll a,ll b,ll m)
{
    return ((b)?(big_mul((a<<1)%m,b>>1,m)%m+((b&1)?a:0)):0)%m;
}

ll number_theory::mod_number(ll num,ll mod)
{
    return (num % mod + mod) % mod;
}

///start combinatorics function

ll number_theory::nPr(ll n,ll p)
{
    return ((fac[n]%MOD)*(modinv(fac[p])%MOD))%MOD;
}

ll number_theory::nCr(ll n,ll p)
{
    return ((nPr(n,p)%MOD)*modinv(fac[n-p])%MOD)%MOD;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    number_theory ntheory;


    return 0;
}
