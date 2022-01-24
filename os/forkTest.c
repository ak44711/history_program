#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 100005
#define Mod 10001
using namespace std;
struct node
{
    int x,y,w;
};
node edge[MAXN];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int n,m,father[MAXN];
int c[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    int minx=INF;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&c[i]);
        minx=min(c[i],minx);
        father[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
        edge[i].w=2*edge[i].w+c[edge[i].x]+c[edge[i].y];
    }
    sort(edge+1,edge+1+m,cmp);
    int ans=minx;
    for(int i=1;i<=m;++i)
    {
        int s1=father[edge[i].x];
        int s2=father[edge[i].y];
        if(s1!=s2)
        {
            ans+=edge[i].w;
            father[s2]=s1;
            for(int j=1;j<=n;++j)
                if(father[j]==s2)
                    father[j]=s1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
