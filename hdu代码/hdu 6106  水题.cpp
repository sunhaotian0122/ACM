#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
int sz[10];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int ans = -INF;
        scanf("%d",&n);
        while(n--)
        {
            for(int i=1;i<=7;i++) scanf("%d",&sz[i]);
            int tmp = 0;
            if(sz[1]-sz[4]-sz[6]+sz[7]>=0) tmp += sz[1]-sz[4]-sz[6]+sz[7];
            else continue;
            if(sz[2]-sz[4]-sz[5]+sz[7]>=0) tmp += sz[2]-sz[4]-sz[5]+sz[7];
            else continue;
            if(sz[3]-sz[5]-sz[6]+sz[7]>=0) tmp += sz[3]-sz[5]-sz[6]+sz[7];
            else continue;
            if(sz[4]-sz[7]>=0) tmp += sz[4]-sz[7];
            else continue;
            if(sz[5]-sz[7]>=0) tmp += sz[5]-sz[7];
            else continue;
            if(sz[6]-sz[7]>=0) tmp += sz[6]-sz[7];
            else continue;
            if(sz[7]>=0) tmp += sz[7];
            else continue;
            ans = max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
