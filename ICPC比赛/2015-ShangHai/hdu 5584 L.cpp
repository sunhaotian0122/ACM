#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

int main()
{
    int t,a,b,x,ans;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        ans=1;
        x = gcd(a,b);
        while(b%(x+a)==0)
        {
            ans++;
            b = b/(a/x+1);
            if(a>b) swap(a,b);
            x = gcd(a,b);
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
