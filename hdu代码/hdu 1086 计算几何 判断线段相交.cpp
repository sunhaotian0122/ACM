#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
}b[105],e[105];
typedef Point Vector;
//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}

bool Segment_Intersect(Point A1,Point A2,Point B1,Point B2)
{
    if(max(A1.x,A2.x)>=min(B1.x,B2.x) &&
       max(B1.x,B2.x)>=min(A1.x,A2.x) &&
       max(A1.y,A2.y)>=min(B1.y,B2.y) &&
       max(B1.y,B2.y)>=min(A1.y,A2.y) && //快速排斥实验
       dcmp(((B1-A1)^(A2-A1))*((A1-B2)^(A2-A1)))>=0 && //跨立实验
       dcmp(((A1-B1)^(B2-B1))*((B1-A2)^(B2-B1)))>=0)
       return true;
    else return false;
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf %lf %lf %lf",&b[i].x,&b[i].y,&e[i].x,&e[i].y);
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(Segment_Intersect(b[i],e[i],b[j],e[j]))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
