#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

#define mod 1000000007
typedef long long ll;
char sz[50005];
ll s[50005][105],ss[50005][105],c[105][105];

void init()
{
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i) c[i][j]=1;
            else c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    for(int i=0;i<=50000;i++) s[i][0] = ss[i][0] = 1;
}

int main()
{
    init();
    int t;
    //freopen("in.txt","r",stdin);
    //freopen("hout.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        getchar();
        gets(sz);
        for(int i=1;i<=n;i++)
        {
            s[i][1] = (s[i-1][1] + (sz[i-1]-'0'))%mod;
            for(int j=2;j<=k;j++) s[i][j] = (s[i][j-1]*s[i][1])%mod;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                ss[i][j] = (s[i][j]+ss[i-1][j])%mod;
        }
        ll tmp,ans;
        for(int i=1;i<=n;i++)
        {
            ans = 0;
            for(int j=0;j<=k;j++)
            {
                tmp = (c[k][j]*s[i][j])%mod;
                if((k-j)&1) ans -= (tmp*ss[i-1][k-j])%mod;
                else ans += (tmp*ss[i-1][k-j])%mod;
                ans %= mod;
            }
            if(i==1) printf("%lld",(ans+mod)%mod);
            else printf(" %lld",(ans+mod)%mod);
        }
        printf("\n");
    }
    return 0;
}
