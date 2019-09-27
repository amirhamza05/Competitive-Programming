#include<bits/stdc++.h>
#define MAX 100007
using namespace std;

int p[MAX],co[MAX],mx[MAX];

int find_parent(int x)
{
    return p[x]=(p[x]==x)?x:find_parent(p[x]);
}
void union_set(int x,int y)
{
    x=find_parent(x);
    y=find_parent(y);
    if(x==y)
        return;
    if(co[x]<co[y])
        swap(x,y);
    co[x]+=co[y];
    p[y]=x;
}

int main()
{


    return 0;
}
