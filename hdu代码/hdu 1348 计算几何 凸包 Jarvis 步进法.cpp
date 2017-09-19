#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e3+5;
const double eps = 1e-8;
const double PI = acos(-1);

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}

	//����+
	Point operator +(const Point &b)const
	{
		return Point(x+b.x,y+b.y);
	}
	//����-
	Point operator -(const Point &b)const
	{
		return Point(x-b.x,y-b.y);
	}
	//���
	double operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//���
	//P^Q>0,P��Q��˳ʱ�뷽��<0��P��Q����ʱ�뷽��=0��P��Q���ߣ�����ͬ�����
	double operator ^(const Point &b)const
	{
		return x*b.y - b.x*y;
	}
	//�����ã�����x�������С�������x��ͬ����ô����y��С����
    bool operator <(const Point &a)const
    {
        return y<a.y||(y==a.y&&x<a.x);
    }
}polygon[maxn];
typedef Point Vector;
//��̬�������ж�����double��eps�����µĴ�С��ϵ
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}

int n,r,sta[maxn],convex_hull[maxn],cnt,num;

void Jarvis()
{
    sort(polygon+1,polygon+n+1);
    cnt=num=0;
    sta[cnt++]=1,sta[cnt++]=2;
    for(int i=3;i<=n;i++)
    {
        while(cnt>1 && dcmp((polygon[i]-polygon[sta[cnt-2]])^(polygon[sta[cnt-1]]-polygon[sta[cnt-2]]))>=0)
            cnt--;
        sta[cnt++]=i;
    }
    for(int i=0;i<cnt;i++) convex_hull[++num]=sta[i];
    cnt=0,sta[cnt++]=n,sta[cnt++]=n-1;
    for(int i=n-2;i>=1;i--)
    {
        while(cnt>1 && dcmp((polygon[i]-polygon[sta[cnt-2]])^(polygon[sta[cnt-1]]-polygon[sta[cnt-2]]))>=0)
            cnt--;
        sta[cnt++]=i;
    }
    for(int i=0;i<cnt;i++) convex_hull[++num]=sta[i];
}

double point_dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&r);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&polygon[i].x,&polygon[i].y);
        Jarvis();
        double ans = 2*PI*r;
        for(int i=1;i<num;i++)
        {
            ans += point_dis(polygon[convex_hull[i]],polygon[convex_hull[i+1]]);
        }
        if(t>0) printf("%.0f\n\n",ans);
        else printf("%.0f\n",ans);
    }
    return 0;
}
