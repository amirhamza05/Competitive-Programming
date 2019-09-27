#include<bits/stdc++.h>
#define MAX 100007
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll big_in[MAX],visit[MAX],mod_inverse;

struct Hash
{
    ll hash_prime,i;

    Hash()
    {
        hash_prime=79;
        for(i=1; i<=MAX-4; i++)
            big_in[i]=bigmod(hash_prime,i);
        mod_inverse=mod_inv(hash_prime);
    }

    ll bigmod(ll n,ll k)
    {
        if(k==0)
            return 1;
        ll x=bigmod(n,k>>1);
        x=(x*x)%MOD;
        ll ret=(k&1)?(x*n)%MOD:(x)%MOD;
        big_in[k]=visit[k]=x;
        return ret;
    }

    ll mod_inv(ll n)
    {
        return bigmod(n,MOD-2);
    }

    ll mod(ll a, ll b)
    {
        return (a % b + b) % b;
    }

    bool sub_string_check(string st,string st1)
    {
        ll j,c=0,a;
        ll hash_val1=0,hash_val=0;

        for(j=0; j<st1.size(); j++)
        {
            char ch=st1[j];
            a=ch*big_in[j+1];
            hash_val=((a%MOD)+(hash_val%MOD))%MOD;
        }

        for(j=0; j<st.size(); j++)
        {

            char ch=st[j];
            c++;
            if(c==st1.size())
            {
                a=ch*big_in[c];
                hash_val1=((a%MOD)+(hash_val1%MOD))%MOD;
                if(hash_val==hash_val1)
                    return 1;
                a=j-c+1;
                ch=st[a];
                a=ch*big_in[1];
                hash_val1=mod(hash_val1-a,MOD);
                hash_val1=(hash_val1*mod_inverse)%MOD;
                c--;
            }
            else
            {
                a=ch*big_in[c];
                hash_val1=((a%MOD)+(hash_val1%MOD))%MOD;
            }
        }
        return 0;
    }

};


int main()
{



    return 0;
}
