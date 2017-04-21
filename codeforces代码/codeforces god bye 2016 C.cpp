#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int n,l,r,a,b,ans;
    while(~scanf("%d",&n))
    {
        l=-INF,r=INF;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            if(b==1&&l<1900) l=1900;
            if(b==2&&r>1899) r=1899;
            l+=a;
            r+=a;
        }
        ans = max(l,r);
        if(r<l) printf("Impossible\n");
        else if(ans>20001899) printf("Infinity\n");
        else printf("%d\n",ans);
    }
    return 0;
}
