#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
const double PI = acos(-1);

const int maxn = 1e5+5;
int n,m;

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
}polygon[maxn];
typedef Point Vector;

//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}

//判断点Q是否在P1和P2的线段上
bool OnSegment(Point P1,Point P2,Point Q)
{
    return dcmp((P1-Q)^(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0;
}

//判断点P在多边形内-O(logn) 顺时针给出
bool InPolygon(Point P)
{
    if(dcmp((polygon[n]-polygon[1])^(P-polygon[1]))<=0 || dcmp((polygon[2]-polygon[1])^(P-polygon[1]))>=0)
        return false;
    int l=2,r=n,mid;
    while(l<r)
    {
        mid = (l+r+1)>>1;
        if(dcmp((polygon[mid]-polygon[1])^(P-polygon[1]))<=0) l=mid;
        else r = mid-1;
    }
    if(dcmp((polygon[l+1]-polygon[l])^(P-polygon[l]))>=0) return false;
    return true;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%lf %lf",&polygon[i].x,&polygon[i].y);
        Point test;
        bool flag = true;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%lf %lf",&test.x,&test.y);
            if(!flag) continue;
            if(!InPolygon(test)) flag = false;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
