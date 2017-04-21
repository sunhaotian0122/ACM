#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,dist[105][105];

int floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist[1][n];
}

int main()
{
    int a,b,c;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(dist,INF,sizeof(dist));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            dist[a][b]=dist[b][a]=c;
        }
        for(int i=1;i<=n;i++) dist[i][i]=0;
        printf("%d\n",floyd());
    }
    return 0;
}
