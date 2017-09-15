#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
const double PI = acos(-1);

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
}polygon[105];
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

//判断点P在多边形内-改进弧长法
bool InPolygon(Point P)
{
    int q1,q2,ans=0;
    Point P1,P2;
    Vector V1,V2;
    for(int i=1,j=n;i<=n;j=i++)
    {
        P1 = polygon[j];
        P2 = polygon[i];
        V1 = P1-P;
        V2 = P2-P;
        if(OnSegment(P1,P2,P)) return true;
        q1 = V1.x>0 ? (V1.y>0 ? 0:3) : (V1.y>0 ? 1:2);
        q2 = V2.x>0 ? (V2.y>0 ? 0:3) : (V2.y>0 ? 1:2);
        int g = (q2-q1+4)%4;
        if(g==1) ans--; //在上一象限
        if(g==3) ans++; //在下一象限
        if(g==2) dcmp(V1^V2)>0 ? (ans-=2) : (ans+=2);
    }
    return ans!=0;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%lf %lf",&polygon[i].x,&polygon[i].y);
        Point test;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%lf %lf",&test.x,&test.y);
            if(InPolygon(test)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
