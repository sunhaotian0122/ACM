#include <bits/stdc++.h>
using namespace std;

int sa[20],sb[20];

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

int main()
{
    int T,n,i,p,q,tmp,x;
    scanf("%d",&T);
    for(x=1;x<=T;x++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&sa[i]);
        for(i=1;i<=n;i++) scanf("%d",&sb[i]);
        p=sb[n];
        q=sa[n];
        for(i=n-1;i>=1;i--)
        {
            tmp = q;
            q = p+sa[i]*q;
            p = sb[i]*tmp;
        }
        i = gcd(p,q);
        p /= i;
        q /= i;
        printf("Case #%d: %d %d\n",x,p,q);
    }
    return 0;
}
