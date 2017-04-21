#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll mmin(ll a,ll b)
{
    return a>b ? b : a;
}

int main()
{
    ll a,b,n,ans;
    ll sum,tmp;
    while(~scanf("%lld%lld%lld",&a,&b,&n))
    {
        sum = 1000000000000000;
        ans = 10000000;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                tmp = n*a/i+n*b*i;
                if(tmp<=sum)
                {
                    if(tmp<sum) ans = i;
                    if(tmp==sum) ans = mmin(ans,i);
                    sum = tmp;
                }
                tmp = i*a+n*b*(n/i);
                if(tmp<sum)
                {
                    ans = n/i;
                    sum = tmp;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
