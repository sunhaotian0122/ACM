//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 1005;
int sz[maxn][maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y)
{
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
            sz[i][j] ^= 1;
}

int query(int x,int y)
{
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            ans ^= sz[i][j];
    return ans;
}

int main()
{
    int T;
    int n,q,x1,x2,y1,y2;
    char op;
    scanf("%d",&T);
    while(T--)
    {
        memset(sz,0,sizeof(sz));
        scanf("%d%d",&n,&q);
        while(q--)
        {
            getchar();
            scanf("%c",&op);
            if(op=='C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                update(x1,y1);
                update(x1,y2+1);
                update(x2+1,y1);
                update(x2+1,y2+1);
            }
            else
            {
                scanf("%d%d",&x1,&y1);
                printf("%d\n",query(x1,y1));
            }
        }
        printf("\n");
    }
    return 0;
}
