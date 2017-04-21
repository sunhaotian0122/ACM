#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 7;
const int maxn=100005;
int ans[maxn];

void pow_mod()
{
    int a,x,num=0;
    for(int i=1;i<maxn;i++)
    {
        ans[i]=1;
        x = i;
        a = 2;
        while(x)
        {
            if(x&1) ans[i] = (ans[i]*a)%mod;
            a = (a*a)%mod;
            x >>= 1;
        }
        if(ans[i]%mod==1) num++;
        ans[i] = num;
    }
}

int main()
{
    pow_mod();
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",ca,ans[n]);
    }
    return 0;
}
