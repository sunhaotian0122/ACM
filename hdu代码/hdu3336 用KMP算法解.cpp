#include <cstdio>
#include <cstring>
using namespace std;

const int mod=1e4+7,maxn=2e6+5;
char str[maxn];
int next[maxn],n;

void set_next()
{
    next[0]=next[1]=0;
    for(int i=1;i<n;i++)
    {
        int tmp=next[i];
        while(tmp && str[i]!=str[tmp]) tmp=next[tmp];
        if(str[i]==str[tmp]) tmp++;
        next[i+1]=tmp;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        scanf("%s",str);
        set_next();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=i;
            while(tmp)
            {
                ans++;
                if(ans>mod) ans%=mod;
                tmp=next[tmp];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
