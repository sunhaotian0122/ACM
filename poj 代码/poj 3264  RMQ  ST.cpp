//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 5e5+5;
int ma[maxn][20],mi[maxn][20];
int n,m;

void init()
{
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            ma[i][j] = max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
            mi[i][j] = min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int l,int r)
{
    int k=0;
    int res=r-l+1;
    while((1<<(k+1))<=res) k++;
    int ans1 = max(ma[l][k],ma[r-(1<<k)+1][k]);
    int ans2 = min(mi[l][k],mi[r-(1<<k)+1][k]);
    return ans1-ans2;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&ma[i][0]),mi[i][0]=ma[i][0];
    init();
    int l,r;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",RMQ(l,r));
    }
    return 0;
}
