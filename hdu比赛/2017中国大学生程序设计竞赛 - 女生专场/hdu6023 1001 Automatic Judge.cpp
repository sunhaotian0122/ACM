#include <bits/stdc++.h>
using namespace std;

int vis[15],_time[15];

int main()
{
    int T,n,m,ans,num,h,mi;
    char str[5];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        memset(vis,0,sizeof(vis));
        memset(_time,0,sizeof(_time));
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d:%d %s",&num,&h,&mi,str);
            num %= 1000;
            if(vis[num]) continue;
            if(strcmp(str,"AC")==0)
            {
                vis[num]=1;
                ans += h*60+mi+_time[num];
            }
            else
            {
                _time[num] += 20;
            }
        }
        num = 0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) num++;
        }
        printf("%d %d\n",num,ans);
    }
    return 0;
}
