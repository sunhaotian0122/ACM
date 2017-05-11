#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int sz[maxn][maxn],status[maxn][maxn];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y,int value)
{
    for(int i=x;i<=maxn;i+=lowbit(i))
        for(int j=y;j<=maxn;j+=lowbit(j))
            sz[i][j] += value;
}

int query(int x,int y)
{
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            ans += sz[i][j];
    return ans;
}

int main()
{
    int T;
    int x1,x2,y1,y2;
    char op;
    memset(sz,0,sizeof(sz));
    memset(status,0,sizeof(status));
    scanf("%d",&T);
    while(T--)
    {
        getchar();
        scanf("%c",&op);
        switch(op)
        {
        case 'B':
            scanf("%d%d",&x1,&y1);
            x1++,y1++;
            if(status[x1][y1]==0)
            {
                update(x1,y1,1);
                status[x1][y1]=1;
            }
            break;
        case 'D':
            scanf("%d%d",&x1,&y1);
            x1++,y1++;
            if(status[x1][y1]>0)
            {
                update(x1,y1,-1);
                status[x1][y1]=0;
            }
            break;
        case 'Q':
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            x1++,x2++,y1++,y2++;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            printf("%d\n",query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1));
            break;
        }
    }
    return 0;
}
