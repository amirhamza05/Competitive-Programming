#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char,int>mp;

struct trie
{
    trie *child[6];
    int total;
    trie()
    {
        total=0;
        for(int i=1; i<5; i++)
            child[i]=NULL;
    }
    void del()
    {
        for(int i=1; i<5; i++)
        {
            if(child[i]!=NULL)
            {
                child[i]->del();
                delete child[i];
            }
        }
    }

    void add_word(trie *curr,string st,int pos)
    {
        if(pos==st.size())
            return;
        int n=mp[st[pos]];
        trie *node=curr->child[n];
        if(node==NULL)
            node=new trie();
        curr->child[n]=node;
        node->total++;
        add_word(node,st,++pos);
    }

    int solve(trie *curr,string st,int pos,ll ans)
    {
        if(pos==st.size())
            return ans;
        int n=mp[st[pos]];
        trie *node=curr->child[n];
        return solve(node,st,pos+1,max((ll)node->total*(pos+1),ans));
    }

} *root;

void solve()
{

    string st;
    vector<string>v;
    root=new trie();
    int i,n;
    ll mx=-1;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> st;
        v.push_back(st);
        root->add_word(root,st,0);
    }
    for(i=0; i<n; i++)
    {
        st=v[i];
        mx=root->solve(root,st,0,mx);
    }
    cout << mx << "\n";
    root->del();
    delete root;
}

int main()
{

    mp['A']=1;
    mp['C']=2;
    mp['G']=3;
    mp['T']=4;
    int test,i;
    cin >> test;
    for(i=0; i<test; i++)
    {
        cout << "Case " << i+1 << ": ";
        solve();
    }


    return 0;
}

