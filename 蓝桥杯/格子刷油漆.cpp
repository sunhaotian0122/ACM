#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
ll a[1005],b[1005];

int main()
{
    ll ans;
    int n;
    scanf("%d",&n);
    b[1]=1;
    for(int i=2;i<=n;i++) b[i] = b[i-1]*2%mod;
    a[1]=1,a[2]=6;
    for(int i=3;i<=n;i++) a[i] = (b[i]+2*a[i-1]+4*a[i-2])%mod;
    ans = 4*a[n];
    for(int i=2;i<n;i++)
    {
        ans =(ans+(8*b[i-1]*a[n-i]%mod+8*b[n-i]*a[i-1]%mod)%mod)%mod;
    }
    if(n==1) ans=2;
    printf("%lld\n",ans);
    return 0;
}
