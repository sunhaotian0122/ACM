#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
int sum[maxn*2],Y[maxn*2],n,m,num;
struct Point{
    int flag,x,y1,y2;
    Point(){}
    Point(int flag,int x,int y1,int y2):flag(flag),x(x),y1(y1),y2(y2){}

    bool operator <(const Point &b)const
    {
        return x==b.x ? flag<b.flag : x<b.x;
    }
}p[maxn*2];

int lowbit(int x)
{
    return x&(-x);
}

void update(int i,int v)
{
    while(i<=num)
    {
        sum[i] += v;
        i += lowbit(i);
    }
}

int query(int i)
{
    int res = 0;
    while(i>0)
    {
        res += sum[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int x1,x2,y1,y2;
        num=0,m=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(y1==y2)
            {
                if(x1>x2) swap(x1,x2);
                p[++m] = Point(0,x1,y1,1);
                p[++m] = Point(0,x2+1,y1,-1);
                Y[++num] = y1;
            }
            else
            {
                if(y1>y2) swap(y1,y2);
                p[++m] = Point(1,x1,y1,y2);
                Y[++num] = y1;
                Y[++num] = y2;
            }
        }
        sort(p+1,p+1+m);
        sort(Y+1,Y+1+num);
        memset(sum,0,sizeof(sum));
        int tmp = unique(Y+1,Y+1+num)-Y-1;
        num = tmp;
        ll ans = 0;
        for(int i=1;i<=m;i++)
        {
            if(p[i].flag)
            {
                int a = lower_bound(Y+1,Y+1+num,p[i].y1)-Y-1;
                int b = lower_bound(Y+1,Y+1+num,p[i].y2)-Y;
                ans += (ll)query(b)-query(a);
            }
            else
            {
                int a = lower_bound(Y+1,Y+1+num,p[i].y1)-Y;
                update(a,p[i].y2);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
