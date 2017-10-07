#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#define eps 1e-8
#define PI 3.14159265359
using namespace std;
typedef long long ll;

const int maxn = 1505;

//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}
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
    bool operator <(const Point &b)const
    {
        return x<b.x||(x==b.x&&y<b.y);
    }
}P[maxn];
typedef Point Vector;
struct Line{
    Point s,e;
    double A,B,C;
    double angle;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        A = e.y-s.y;
        B = s.x-e.x;
        C = e^s;
        angle = atan2(e.y-s.y,e.x-s.x);
    }
    //两直线相交求交点
    //第一个值为0表示直线重合，为1表示平行，为2是相交
    //只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point ans = Point();
        if(dcmp((e-s)^(b.e-b.s)) == 0)
        {
            if(dcmp((b.e-s)^(b.e-b.s)) == 0)
                return make_pair(0,ans);//重合
            else
                return make_pair(1,ans);//平行
        }
        ans.x = (B*b.C-b.B*C)/(A*b.B-b.A*B);
        ans.y = (b.A*C-A*b.C)/(A*b.B-b.A*B);
        return make_pair(2,ans);
    }
    //半平面交极角排序
    //极角相同取最左边的
    bool operator <(const Line &b)const
    {
        int d = dcmp(angle-b.angle);
        if(d==0) //如果在b的右边就交换
            return dcmp((b.s-s)^(b.e-s)) < 0;
        else
            return d<0;
    }
}L[maxn];

int dq[maxn],top,tal;
int n;

//半平面交排序增量法 nlogn
//半平面顺时针给出 L1,L2交点在L0左边为外 逆时针为右
//这里顺时针为例
bool check(Line L0,Line L1,Line L2)
{
    Point tmp = (L1&L2).second;
    return dcmp((L0.s-tmp)^(L0.e-tmp)) > 0;
}

void HalfPlaneIntersect()
{
    sort(L+1,L+1+n);
    int num=1;
    for(int i=2;i<=n;i++)
    {
        if(dcmp(L[i].angle-L[num].angle)>0)
            L[++num]=L[i];
    }
    dq[0] = 1, dq[1] = 2;
    top = 1, tal = 0;
    for(int i=3;i<=num;i++)
    {
        while(top>tal && check(L[i],L[dq[top]],L[dq[top-1]])) top--;
        while(top>tal && check(L[i],L[dq[tal]],L[dq[tal+1]])) tal++;
        dq[++top] = i;
    }
    while(top>tal && check(L[dq[tal]],L[dq[top]],L[dq[top-1]])) top--;
    while(top>tal && check(L[dq[top]],L[dq[tal]],L[dq[tal+1]])) tal++;
    dq[++top] = dq[tal];
    n = 0;
    for(int i=tal;i<top;i++)
    {
        P[++n] = (L[dq[i]]&L[dq[i+1]]).second;
    }
    P[n+1] = P[1];
}

double PolygonArea()
{
    if(n<3)
        return 0;
    double res = 0;
    for(int i=1;i<=n;i++)
    {
        res += P[i]^P[i+1];
    }
    if(dcmp(res)<0) res = -res;
    res /= 2.0;
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&P[i].x,&P[i].y);
        }
        P[n+1] = P[1];
        for(int i=1;i<=n;i++)
        {
            L[i] = Line(P[i],P[i+1]);
        }
        HalfPlaneIntersect();
        printf("%.2f\n",PolygonArea());
    }
    return 0;
}
