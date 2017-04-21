#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

int sz[10005];
long long ans;

int main()
{
    int n,left,right;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&sz[i]);
        ans=sz[1];
        left=right=sz[1];
        long long sum=0;
        int flag=sz[1];
        for(int i=1;i<=n;i++)
        {
            if(sum<0)
            {
                sum=sz[i];
                flag=sz[i];
            }
            else sum+=sz[i];
            if(sum>ans)
            {
                ans=sum;
                left=flag;
                right=sz[i];
            }
        }
        if(ans<0) printf("0 %d %d\n",sz[1],sz[n]);
        else printf("%lld %d %d\n",ans,left,right);
    }
    return 0;
}
