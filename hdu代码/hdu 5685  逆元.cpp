#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
long long mod=9973;
string s;
long long dp[maxn];

long long qmod(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        b>>=1;
        a = (a*a)%mod;
    }
    return ans;
}

int main()
{
    int n;
    long long a,b;
    while(scanf("%d",&n)!=EOF)
    {
        cin>>s;
        dp[0]=1;
        for(int i=1;i<=s.length();i++)
        {
            dp[i]=(dp[i-1]*(s[i-1]-28))%mod;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a,&b);
            if(a>b) swap(a,b);
            printf("%lld\n",(dp[b]*qmod(dp[a-1],mod-2))%mod);
        }
    }
    return 0;
}
