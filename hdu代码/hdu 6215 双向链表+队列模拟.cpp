#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
int que[maxn*10],nt[maxn],pe[maxn],sz[maxn];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int s=0,num=0,e=0,ans=n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sz[i]);
            nt[i] = i+1;
            pe[i] = i-1;
            que[num++] = i;
        }
        nt[0] = 1,pe[n+1] = n;
        while(e!=num)
        {
            e = num;
            while(s<e)
            {
                int x,y,cnt=0;
                x=y=que[s++];
                while(nt[x]<=n && sz[x]>sz[nt[x]]) x=nt[x],cnt++;
                if(cnt)
                {
                    ans -= cnt+1;
                    nt[pe[y]] = nt[x];
                    pe[nt[x]] = pe[y];
                    que[num++] = pe[y];
                }
                while(s<e && que[s]<=x) s++;
            }
        }
        printf("%d\n",ans);
        for(int i=nt[0];i<=n;i=nt[i]) printf("%d ",sz[i]);
        printf("\n");
    }
    return 0;
}
