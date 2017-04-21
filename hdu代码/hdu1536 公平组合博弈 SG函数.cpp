#include <bits/stdc++.h>
using namespace std;
const int maxm=105,maxn=10005;
int m,s[maxm],sg[maxn];
bool vis[maxn];

void set_sg()
{
    memset(sg,0,sizeof(sg));
    for(int i=0;i<maxn;i++)
    {
        memset(vis,false,sizeof(vis));
        for(int j=0;j<m&&i>=s[j];j++) vis[sg[i-s[j]]]=true;
        for(int j=0;;j++)
        {
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
        }
    }
    return;
}

int main()
{
    int t,n,ans,tmp;
    while(scanf("%d",&m)&&m)
    {
        for(int i=0;i<m;i++) scanf("%d",&s[i]);
        sort(s,s+m);
        set_sg();
        scanf("%d",&t);
        while(t--)
        {
            ans=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&tmp);
                ans ^= sg[tmp];
            }
            if(ans) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}
