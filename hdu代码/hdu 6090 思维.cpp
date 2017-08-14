#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    ll n,m,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        if(m<n-1) ans = n*(n-m-1)*(m+n)+2*m*m;
        else if(m==n-1) ans = 2*(n-1)*(n-1);
        else
        {
            ans = 2*(n-1)*(n-1);
            ll tmp = m-n+1;
            ans -= 2*tmp;
            if(ans<n*(n-1)) ans = n*(n-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
