#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int pow_max(int a,int b,int c)
{
    int x;
    x = max(a,b);
    x = max(x,c);
    return x;
}
const int INF = 0x3f3f3f3f;
int ans,n,sz[105][105];

void dfs(int a,int b,int c,int sum)
{
    int tmp = pow_max(a,b,c);
    if(tmp==n)
    {
        if(sum<ans) ans=sum;
        return;
    }
    dfs(tmp+1,b,c,sum+sz[a][tmp+1]);
    dfs(a,tmp+1,c,sum+sz[b][tmp+1]);
    dfs(a,b,tmp+1,sum+sz[c][tmp+1]);
}

int main()
{
    int tmp;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&tmp);
            sz[i][j] = sz[j][i] = tmp;
        }
    }
    ans=INF;
    dfs(1,1,1,0);
    printf("%d\n",ans);
}
