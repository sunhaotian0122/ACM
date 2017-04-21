#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll tmp[2][2],sz[2][2],ans[2][2],cmp[2][2];
int mod;

void matrix_multi(ll a[][2],ll b[][2])
{
    memset(cmp,0,sizeof(cmp));
    for(int i=0;i<2;i++)
        for(int k=0;k<2;k++)
            for(int j=0;j<2;j++)
            {
                cmp[i][j]+=a[i][k]*b[k][j]%mod;
                cmp[i][j]%=mod;
            }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=cmp[i][j];

}

void pow_mod(ll a[][2],int b)
{
    ans[0][0]=1;ans[0][1]=0;ans[1][0]=0;ans[1][1]=1;
    while(b)
    {
        if(b&1) matrix_multi(ans,a);
        b>>=1;
        matrix_multi(a,a);
    }
}

int main()
{
    int a,b,n;
    while(~scanf("%d%d%d%d",&a,&b,&n,&mod))
    {
        tmp[0][0]=a;tmp[0][1]=b;tmp[1][0]=1;tmp[1][1]=a;
        sz[0][0]=a;sz[0][1]=0;sz[1][0]=1;sz[1][1]=0;
        pow_mod(tmp,n-1);
        matrix_multi(ans,sz);
        printf("%lld\n",(ll)(2*ans[0][0]%mod));
    }
    return 0;
}
