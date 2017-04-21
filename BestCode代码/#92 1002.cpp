#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn],b[maxn],na[maxn],nb[maxn];

int main()
{
    int T,n,m,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(na,0,sizeof(na));
        memset(nb,0,sizeof(nb));
        for(int i=1;i<=k;i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
            na[a[i]]++;
            nb[b[i]]++;
        }
        ll ans = 0;
        for(int i=1;i<=k;i++)
        {
            ans += (na[a[i]]-1)*(nb[b[i]]-1);
        }
        printf("%lld\n",ans*2);
    }
    return 0;
}
