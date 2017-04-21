#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
int n,mod;
ll tmp[10][10],ans[10][10],sz[10][10],cmp[10][10];

void matrix_multi(ll a[][10],ll b[][10])
{
    memset(cmp,0,sizeof(cmp));
    for(int i=0;i<10;i++)
    {
        for(int k=0;k<10;k++)
        {
            if(a[i][k]==0) continue;
            for(int j=0;j<10;j++)
            {
                cmp[i][j]+=a[i][k]*b[k][j];
                cmp[i][j]%=mod;
            }
        }
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            a[i][j]=cmp[i][j];
}

void pow_mod(ll a[][10])
{
    memset(ans,0,sizeof(ans));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(i==j) ans[i][j]=1;
    int b=n-9;
    while(b)
    {
        if(b&1) matrix_multi(ans,a);
        b>>=1;
        matrix_multi(a,a);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&mod))
    {
        memset(tmp,0,sizeof(tmp));
        memset(sz,0,sizeof(sz));
        for(int i=0;i<10;i++) scanf("%lld",&tmp[0][i]);
        tmp[1][0]=tmp[2][1]=tmp[3][2]=tmp[4][3]=tmp[5][4]=tmp[6][5]=tmp[7][6]=tmp[8][7]=tmp[9][8]=1;
        for(int i=0;i<10;i++) sz[i][0]=9-i;
        pow_mod(tmp);
        matrix_multi(ans,sz);
        printf("%lld\n",ans[0][0]);
    }
    return 0;
}
