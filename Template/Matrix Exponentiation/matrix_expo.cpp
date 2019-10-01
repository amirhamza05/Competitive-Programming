#include<bits/stdc++.h>
#define MOD 10007
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > vmat;
typedef vector<ll> vmat1;

struct Matrix
{
    vmat mat;
    ll row, col;

    Matrix() {}
    Matrix(vector<vector<ll> > values): mat(values), row(values.size()),
        col(values[0].size()) {}

    Matrix Identity_Matrix(ll n)
    {
        vmat value(n,vmat1(n,0));
        for(ll i=0; i<n; i++)
            value[i][i]=1;
        return value;
    }

    Matrix zero_Matrix()
    {
        vmat value(row,vmat1(col,0));
        return value;
    }

    Matrix operator*(Matrix other)
    {
        ll n=row,m=other.col;
        vmat res(n,vmat1(m,0));
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                for(ll k=0; k<col; k++)
                    res[i][j]=(res[i][j]+(mat[i][k]*other.mat[k][j])%MOD)%MOD;
        return res;
    }

    Matrix operator+(Matrix other)
    {
        ll n=row,m=col;
        vmat res(n,vmat1(m,0));
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                res[i][j]=(mat[i][j]+other.mat[i][j])%MOD;
        return res;
    }

    Matrix power(ll k)
    {
        if(k==1)
            return mat;
        Matrix x=power(k/2);
        x=(x*x);
        return (k&1)?x*mat:x;
    }

};


int main()
{
    vmat val({{1,1},{1,0}});
    Matrix M(val),res;

    ll n,ans,i,j;
    cin >> n;

    res=M.power(n-2);
    ans=(res.mat[0][0]*1)+(res.mat[0][1]*0);

    cout << ans << "\n";



    return 0;
}
