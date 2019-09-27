#include<bits/stdc++.h>
using namespace std;

struct sqrt_decom
{

    vector<vector<int> >v,v1;
    vector<int>in;
    int s;
    sqrt_decom(vector<int>v1)
    {
        int s1=sqrt(v1.size())+1;
        vector<vector<int> >v2(s1);
        this->v=v2;
        this->in=v1;
        this->v1=v;
        this->s=s1;
    }

    void ini()
    {
        int i,j;
        for(i=0; i<in.size(); i++)
        {
            v[(int)i/s].push_back(in[i]);
        }
        for(i=0; i<s; i++)
        {
            v1[i]=v[i];
            sort(v1[i].begin(),v1[i].end());
        }
    }

    void update(int pos,int val)
    {
        int b_pos=pos/s,v_pos_n=pos%s;
        v[b_pos][v_pos_n]=val;
        v1[b_pos]=v[b_pos];
        in[pos]=val;
        sort(v1[b_pos].begin(),v1[b_pos].end());
    }
    int query(int l,int r,int val)
    {
        int l1=l/s,r1=r/s,i,c=0;
        if(l1==r1)
        {
            for(i=l; i<=r; i++)
            {
                if(in[i]>=val)
                    c++;
            }
            return c;
        }

        for(i=(l%s); i<v[l1].size(); i++)
            c+=(v[l1][i]>=val)?1:0;
        for(i=0; i<=(r%s); i++)
            c+=(v[r1][i]>=val)?1:0;

        for(i=l1+1; i<r1; i++)
        {
            int cal=lower_bound(v1[i].begin(),v1[i].end(),val)-v1[i].begin();
            cal=v1[i].size()-cal;
            c+=cal;
        }

        return c;

    }

};
int main()
{

    int n,q,i,a,b,l,r,ans,c;
    vector<int>v;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sqrt_decom decom(v);
    decom.ini();
    cin >> q;
    for(i=0; i<q; i++)
    {
        cin >> a >> l >> r;
        l--,r--;
        if(a==0)
        {
            cin >> c;
            ans=decom.query(l,r,c);
            cout << ans << "\n";
        }
        else
        {
            decom.update(l,r);
        }
    }


    return 0;
}


