#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
const double eps = 1e-8;

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
        return y<b.y||(y==b.y&&x<b.x);
    }
}poly[maxn];
typedef Point Vector;

int n;

bool isconvex()
{
    bool s[3];
    memset(s,false,sizeof(s));
    for(int i=0;i<n;i++)
    {
        s[dcmp((poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i])) + 1] = true;
        if(s[0] && s[2]) return false;
    }
    return true;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf",&poly[i].x,&poly[i].y);
        }
        if(isconvex()) printf("convex\n");
        else printf("concave\n");
    }
    return 0;
}
