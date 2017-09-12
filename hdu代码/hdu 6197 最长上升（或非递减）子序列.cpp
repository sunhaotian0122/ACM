#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;

int a[maxn],n,k;
int d[maxn],len;

void binary_search(int x)
{
    int l=0,r=len,mid;
    while(l<r)
    {
        mid = (l+r+1)>>1;
        if(d[mid]<=x) l = mid;
        else r = mid-1;
    }
    if(l) d[l+1]=x;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        len=1,d[1]=a[1],d[0]=0;
        for(int i=2;i<=n;i++)
        {
            if(d[len]<=a[i]) d[++len] = a[i];
            else binary_search(a[i]);
        }
        if(len+k>=n) printf("A is a magic array.\n");
        else
        {
            for(int i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
            len=1,d[1]=a[1],d[0]=0;
            for(int i=2;i<=n;i++)
            {
                if(d[len]<=a[i]) d[++len] = a[i];
                else binary_search(a[i]);
            }
            if(len+k>=n) printf("A is a magic array.\n");
            else printf("A is not a magic array.\n");
        }
    }
    return 0;
}
