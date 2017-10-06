#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define eps 1e-8
#define PI 3.14159265359
using namespace std;
typedef long long ll;

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
};
typedef Point Vector;
struct Line{
    Point s,e;
    double A,B,C;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        A = e.y-s.y;
        B = s.x-e.x;
        C = e^s;
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
};

int n,m;
Point an[105],bn[105],cn[105];

void HalfPlaneIntersect(Line L)
{
    int num=0;
    for(int i=1;i<=m;i++)
    {
        if(dcmp(L.A*bn[i].x+L.B*bn[i].y+L.C)>=0) cn[++num] = bn[i];
        else
        {
            if(dcmp(L.A*bn[i-1].x+L.B*bn[i-1].y+L.C)>0) cn[++num] = (Line(bn[i-1],bn[i])&L).second;
            if(dcmp(L.A*bn[i+1].x+L.B*bn[i+1].y+L.C)>0) cn[++num] = (Line(bn[i+1],bn[i])&L).second;
        }
    }
    for(int i=1;i<=num;i++) bn[i] = cn[i];
    bn[0] = cn[num];
    bn[num+1] = cn[1];
    m=num;
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
            scanf("%lf %lf",&an[i].x,&an[i].y);
            bn[i] = an[i];
        }
        bn[0] = an[0] = an[n];
        bn[n+1] = an[n+1] = an[1];
        m=n;
        for(int i=1;i<=n;i++)
        {
            Line L = Line(an[i],an[i+1]);
            HalfPlaneIntersect(L);
        }
        if(m) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
