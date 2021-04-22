struct SqrtDecom {
    vector<vector<ll>>block;
    vector<ll>blockResult;
    ll sz;
    SqrtDecom(vector<ll>v) {
        sz = sqrt(v.size()) + 1;
        build(v);
    }
    void build(vector<ll>v) {
        block.resize(sz);
        blockResult.resize(sz,0);
        for(ll i = 0; i<v.size(); i++) {
            block[i/sz].push_back(v[i]);
            blockResult[i/sz] += v[i];
        }
    }
    void update(ll pos,ll val) {
        blockResult[pos/sz] -= block[pos/sz][pos%sz];
        blockResult[pos/sz] += val;
        block[pos/sz][pos%sz] = val;
    }
    ll query(ll l,ll r) {
        ll i,l1 = l/sz,r1 = r/sz,res = 0;
        if(l1 == r1) {
            for(i=l%sz; i<=r%sz; i++)res += block[l1][i];
            return res;
        }
        for(i=l1+1; i<r1; i++)res += blockResult[i];
        for(i=l%sz; i<sz; i++)res += block[l1][i];
        for(i=0; i<=r%sz; i++)res += block[r1][i];
        return res;
    }
};

