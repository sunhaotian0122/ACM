#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    ll n,k,x,tmp;
    bool flag;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%lld%lld",&n,&k);
        printf("Case #%d:\n",ca);
        x = (1<<k)-1-n;
        if(x&1)
        {
            flag=true;
            x++;
        }
        else flag = false;
        x>>=1;
        for(int i=0;i<k-1;i++)
        {
            tmp = 1<<i;
            if(x&1) printf("%lld -\n",tmp);
            else printf("%lld +\n",tmp);
            x>>=1;
        }
        x = 1<<(k-1);
        if(flag) printf("%lld +\n",x+1);
        else printf("%lld +\n",x);
    }
    return 0;
}
