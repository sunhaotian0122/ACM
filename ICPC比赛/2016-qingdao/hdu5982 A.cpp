#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans = 0;
        int a,b;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&a,&b);
            ans += a*b;
        }
        printf("%d\n",ans);
    }
    return 0;
}
