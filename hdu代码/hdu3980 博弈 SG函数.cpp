#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int sg[1005];
bool vis[1005];

void set_sg()
{
   memset(sg,0,sizeof(sg));
   for(int i=0;i<=n;i++)
   {
       memset(vis,false,sizeof(vis));
       for(int j=0;i-j-m>=0;j++) vis[sg[j]^sg[i-j-m]]=true;
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
    scanf("%d", &t);
    for(int ca=1; ca<=t; ca++)
    {
        scanf("%d%d", &n, &m);
        set_sg();
        if(n<m || sg[n-m]) printf("Case #%d: abcdxyzk\n",ca);
        else printf("Case #%d: aekdycoin\n",ca);
    }
    return 0;
}
