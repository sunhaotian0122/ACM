#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int sz[maxn],n,k;

int main()
{
    long long num,ans,tmp,sum;
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%d%d",&n,&k);
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sz[i]);
            sum+=sz[i];
        }
        if(k==1)
        {
            printf("Case #%d: %d\n",ca,n-1);
            continue;
        }
        num=sum%k;
        if(num)
        {
            printf("Case #%d: -1\n",ca);
            continue;
        }
        num = sum/k;
        ans=0;
        tmp=0;
        for(int i=1;i<=n;i++)
        {
            if(tmp+sz[i]<num)
            {
                if(tmp) ans++;
                tmp+=sz[i];
            }
            else if(tmp+sz[i]==num)
            {
                if(tmp) ans++;
                tmp=0;
            }
            else
            {
                if(tmp) ans++;
                if((sz[i]+tmp)%num) ans += ((sz[i]+tmp)/num);
                else ans += ((sz[i]+tmp)/num-1);
                tmp =(sz[i]+tmp)%num;
            }
        }
        printf("Case #%d: %lld\n",ca,ans);
    }
    return 0;
}
