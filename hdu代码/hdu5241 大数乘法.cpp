#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn=1000010;
int num[maxn],len;

void solve(int n)
{
    int tmp;
    memset(num,0,sizeof(num));
    num[1]=1; len=1;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        for(int j=1;j<=len;j++)
        {
            num[j] *= 32;
            num[j] += tmp;
            tmp = num[j]/100;
            num[j] %= 100;
        }
        while(tmp)
        {
            num[++len] = tmp%100;
            tmp /= 100;
        }
    }
}

int main()
{
    int T,n,ca;
    scanf("%d",&T);
    for(ca=1;ca<=T;ca++)
    {
        scanf("%d",&n);
        solve(n);
        printf("Case #%d: ",ca);
        for(int i=len;i>0;i--)
        {
            if(i!=len) printf("%02d",num[i]);
            else printf("%d",num[i]);
        }
        printf("\n");
    }
    return 0;
}
