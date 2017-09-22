#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-8;
const double PI = acos(-1);

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
//求点P关于直线L的对称点
Point symmetry_point(Point P,Line L)
{
    Point ans = Point();
    ans.x = P.x-2*L.A*(L.A*P.x+L.B*P.y+L.C)/(L.A*L.A+L.B*L.B);
    ans.y = P.y-2*L.B*(L.A*P.x+L.B*P.y+L.C)/(L.A*L.A+L.B*L.B);
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Point X1,X2,Y1,Y2,tmp;
        scanf("%lf %lf",&X1.x,&X1.y);
        scanf("%lf %lf",&X2.x,&X2.y);
        scanf("%lf %lf",&Y1.x,&Y1.y);
        scanf("%lf %lf",&tmp.x,&tmp.y);
        Line L1 = Line(X1,X2);
        Y2 = symmetry_point(tmp,L1);
        Line L2 = Line(Y1,Y2);
        pair<int,Point> ans = L1&L2;
        printf("%.3f %.3f\n",fabs(ans.second.x)<0.001 ? 0 : ans.second.x,fabs(ans.second.y)<0.001 ? 0 : ans.second.y);
    }
    return 0;
}
