#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 105;
const double eps = 1e-8;
const double PI = acos(-1);

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}

	//向量+
	Point operator +(const Point &b)const
	{
		return Point(x+b.x,y+b.y);
	}
	//向量-
	Point operator -(const Point &b)const
	{
		return Point(x-b.x,y-b.y);
	}
	//点积
	double operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//叉积
	//P^Q>0,P在Q的顺时针方向；<0，P在Q的逆时针方向；=0，P，Q共线，可能同向或反向
	double operator ^(const Point &b)const
	{
		return x*b.y - b.x*y;
	}
	//排序用，按照x的坐标从小到大，如果x相同，那么按照y从小到大
    bool operator <(const Point &a)const
    {
        return y<a.y||(y==a.y&&x<a.x);
    }
}polygon[maxn];
typedef Point Vector;
//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}
//计算两点之间的距离
double point_dis(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
//极角排序
bool cmp(Point a,Point b)
{
    double tmp = (a-polygon[1])^(b-polygon[1]);
    if(dcmp(tmp)>0) return true;
    else if(dcmp(tmp)==0 && dcmp(point_dis(polygon[1],a)-point_dis(polygon[1],b))<0) return true;
    else return false;
}

int n,r,convex_hull[maxn],num;

void Graham()
{
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(dcmp(polygon[i].y-polygon[k].y)<0 || (dcmp(polygon[i].y-polygon[k].y)==0 && dcmp(polygon[i].x-polygon[k].x)<0))
            k = i;
    }
    if(k!=1) swap(polygon[1],polygon[k]);
    sort(polygon+2,polygon+n+1,cmp);
    if(n==1)
    {
        num=1;
        convex_hull[1]=1;
        return;
    }
    if(n==2)
    {
        num=2;
        convex_hull[1]=1;
        convex_hull[2]=2;
        return;
    }
    num=2;
    convex_hull[1]=1;
    convex_hull[2]=2;
    for(int i=3;i<=n;i++)
    {
        while(num>1 && dcmp((polygon[convex_hull[num]]-polygon[convex_hull[num-1]])^(polygon[i]-polygon[convex_hull[num-1]]))<=0)
            num--;
        convex_hull[++num]=i;
    }
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&polygon[i].x,&polygon[i].y);
        }
        Graham();
        double ans = 0;
        for(int i=1;i<num;i++)
        {
            ans += point_dis(polygon[convex_hull[i]],polygon[convex_hull[i+1]]);
        }
        if(num>2) ans += point_dis(polygon[convex_hull[num]],polygon[convex_hull[1]]);
        printf("%.2f\n",ans);
    }
    return 0;
}
