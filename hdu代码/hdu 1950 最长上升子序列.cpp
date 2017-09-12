#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 4e4+5;

int a[maxn],n;
int d[maxn],len;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        len=1,d[1]=a[1],d[0]=0;
        for(int i=2;i<=n;i++)
        {
            if(d[len]<a[i]) d[++len]=a[i];
            else
            {
                int tmp = lower_bound(d,d+len,a[i])-d;
                d[tmp] = a[i];
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
