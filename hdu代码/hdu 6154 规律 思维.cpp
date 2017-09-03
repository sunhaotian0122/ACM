#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5;
ll ans[maxn];
int n;

void init()
{
    for(ll i=4;i<maxn;i++)
    {
        if(i%4==0) ans[i] = i*i/8;
        if(i%4==1) ans[i] = ans[i-1]+i/4-0.5;
        if(i%4==2) ans[i] = (i/4)*(i/4+1)*2;
        if(i%4==3) ans[i] = ans[i-1]+i/4+0.5;
    }
}

int main()
{
    int t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=4;i<maxn;i++)
        {
            if(ans[i]>=n)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
