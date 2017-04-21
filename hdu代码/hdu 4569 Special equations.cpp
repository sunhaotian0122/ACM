#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
int sz[5];
ll f(int x)
{
    ll tmp;
    return tmp=(ll)sz[4]*pow(x,4)+(ll)sz[3]*pow(x,3)+(ll)sz[2]*x*x+(ll)sz[1]*x+sz[0];
}
int main()
{
    int n,T,p,ans;
    bool flag;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(sz,0,sizeof(sz));
        flag=false;
        scanf("%d",&n);
        for(int i=n;i>=0;i--) scanf("%d",&sz[i]);
        scanf("%d",&p);
        for(int i=0;i<=p;i++)
        {
            if(flag) break;
            if(f(i)%p==0)
            {
                for(int j=i;j<=p*p;j+=p)
                {
                    if(f(j)%(p*p)==0)
                    {
                        flag=true;
                        ans=j;
                        break;
                    }
                }
            }
        }
        if(flag) printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: No solution!\n",cas);
    }
    return 0;
}
