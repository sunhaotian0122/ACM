#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,vis[10][10];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int tmp;
        if(n>=6)
        {
            for(int i=1;i<n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    scanf("%d",&tmp);
                }
            }
            printf("Bad Team!\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                scanf("%d",&tmp);
                if(tmp) vis[i][j]=vis[j][i]=1;
            }
        }
        bool flag=true;
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(vis[i][j]==vis[i][k]&&vis[i][j]==vis[j][k])
                    {
                        flag=false;
                    }
                }
            }
        }
        if(flag) printf("Great Team!\n");
        else printf("Bad Team!\n");
    }
    return 0;
}
