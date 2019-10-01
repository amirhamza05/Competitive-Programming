/**
 *    Topic:   Policy Based Data Structures Set
 *    Author:  Sk.Amir Hamza
 *    Created: 01.10.2019
**/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class key,class value= null_type,class cmp= less<key>>
using pbds_set = tree<key,value,cmp,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    int n,a,m,i,c=0;

    //simple set example-----------------------------------
    pbds_set<int>s;
    s.insert(4);
    s.insert(5);
    s.insert(8);

     //order of key= How many number are less then 5
    auto p1=s.order_of_key(5);
    cout << p1 << "\n";
    //find_by_order= Which number occur in index 2
    auto ret1=s.find_by_order(2);
    int r=*ret1;
    cout << r << "\n";

    //multi set example-----------------------------------------
    //you need pair<int,int> use parameter in multi set for make unique all value
    pbds_set<pair<int,int>>multi_set;
    multi_set.insert({1,c++});
    multi_set.insert({4,c++});
    multi_set.insert({7,c++});
    multi_set.insert({9,c++});
    multi_set.insert({4,c++});
    multi_set.insert({11,c++});

    //order of key= How many number are less then 4
    auto p=multi_set.order_of_key({4,1});
    cout << p << "\n";

    //find_by_order= Which number occur in index 1
    auto ret=multi_set.find_by_order(1);
    pair<int,int> pii=*ret;
    cout << pii.first << "\n";





    return 0;
}

