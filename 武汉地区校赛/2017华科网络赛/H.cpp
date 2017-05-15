#include <bits/stdc++.h>
using namespace std;

int sz[1005][1005],n,m,f[1005];

int _find(int a)
{
    return a==f[a] ? a : f[a] = _find(f[a]);
}

int main()
{
    int a,b;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) sz[i][j]=1;
                else sz[i][j]=0;
            }
            f[i]=i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            sz[a][b] = sz[b][a]=1;
        }
        int num=n-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                else
                {
                    int x = _find(i),y = _find(j);
                    if(x!=y&&sz[i][j])
                    {
                        f[max(x,y)] = min(x,y);
                        num--;
                        if(num==0) break;
                    }
                }
            }
            if(num==0) break;
        }
        printf("%d\n",num);
    }
    return 0;
}
