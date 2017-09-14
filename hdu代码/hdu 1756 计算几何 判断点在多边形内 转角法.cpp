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

//判断点P在多边形内-转角法（多边形点顺时针给出）
bool InPolygon(Point P)
{
    int wn = 0;
    Point P1,P2; //多边形一条边的两个顶点
    Vector V1,V2; //被测点与P1分别于P2形成的向量
    for(int i=1,j=n;i<=n;j=i++)
    {
        P1 = polygon[j];  //顺时针中前一点
        P2 = polygon[i];  //顺时针中后一点
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
        V1 = P2-P1;
        V2 = P-P1;
        int k = dcmp(V1^V2);
        int d1 = dcmp(P1.y-P.y);
        int d2 = dcmp(P2.y-P.y);
        if(k>0 && d1<=0&&d2>0) wn--;  //测试点在有向边左边 有向边向上穿过
        if(k<0 && d1>0&&d2<=0) wn++;  //测试点在有向边右边 有向边向下穿过
    }
    return wn!=0;
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
