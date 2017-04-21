#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int sz[10][10],vis[3][20],tmp[3][20],ans,n;

void dfs(int x)
{
    if(x==2*n)
    {
        for(int j=1;j<=n;j++)
        {
            if(sz[n][j] && !tmp[0][j] && !tmp[1][n+j] && !tmp[2][n-j+n])
            {
                ans++;
                return;
            }
        }
    }
    if(x>n)
    {
        int i=x-n;
        for(int j=1;j<=n;j++)
        {
            if(sz[i][j] && !tmp[0][j] && !tmp[1][i+j] && !tmp[2][i-j+n])
            {
                sz[i][j]=0;
                tmp[0][j]=tmp[1][i+j]=tmp[2][i-j+n]=1;
                dfs(x+1);
                tmp[0][j]=tmp[1][i+j]=tmp[2][i-j+n]=0;
                sz[i][j]=1;
            }
        }
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            if(sz[x][j] && !vis[0][j] && !vis[1][x+j] && !vis[2][x-j+n])
            {
                sz[x][j]=0;
                vis[0][j]=vis[1][x+j]=vis[2][x-j+n]=1;
                dfs(x+1);
                vis[0][j]=vis[1][x+j]=vis[2][x-j+n]=0;
                sz[x][j]=1;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&sz[i][j]);
    ans=0;
    memset(vis,0,sizeof(vis));
    memset(tmp,0,sizeof(tmp));
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
