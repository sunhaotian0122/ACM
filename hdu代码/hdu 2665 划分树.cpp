#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
int n,m;
int h[maxn],val[20][maxn],num[20][maxn];

void build(int l,int r,int deep)
{
    if(l==r) return;
    int mid = (l+r)>>1,cnt = mid-l+1;
    for(int i=l;i<=r;i++) if(val[deep][i]<h[mid]) cnt--;
    int ln=l,rn=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(i==l) num[deep][i] = 0;
        else num[deep][i] = num[deep][i-1];
        if(val[deep][i]<h[mid] || val[deep][i]==h[mid]&&cnt>0)
        {
            val[deep+1][ln++] = val[deep][i];
            num[deep][i]++;
            if(val[deep][i]==h[mid]) cnt--;
        }
        else
        {
            val[deep+1][rn++] = val[deep][i];
        }
    }
    build(l,mid,deep+1);
    build(mid+1,r,deep+1);
}

int query(int deep,int s,int e,int l,int r,int k)
{
    if(l==r) return val[deep][l];
    int pre;
    if(l==s) pre=0;
    else pre = num[deep][s-1];
    int mid = (l+r)>>1,cnt = num[deep][e]-pre;
    if(k<=cnt)
    {
        return query(deep+1,l+pre,l+num[deep][e]-1,l,mid,k);
    }
    else
    {
        int rn = mid+1+s-l-pre;
        return query(deep+1,rn,rn+e-s+1-cnt-1,mid+1,r,k-cnt);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&val[0][i]),h[i]=val[0][i];
        sort(h+1,h+1+n);
        build(1,n,0);
        int l,r,k;
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(0,l,r,1,n,k));
        }
    }
    return 0;
}
