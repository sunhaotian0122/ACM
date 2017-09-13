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
};
//排序用，按照x的坐标从小到大，如果x相同，那么按照y从小到大
bool operator < (const Point &a,const Point &b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}
//判断点Q是否在P1和P2的直线上
bool OnBeeline(Point P1,Point P2,Point Q)
{
	return dcmp((P1-Q)^(P2-Q))==0;
}
//判断点Q是否在P1和P2的线段上
bool OnSegment(Point P1,Point P2,Point Q)
{
    return OnBeeline(P1,P2,Q)&&dcmp((P1-Q)*(P2-Q))<=0;
}
//判断点P是否在三角形ABC中
bool InTriangle(Point A,Point B,Point C,Point P)
{
	double Sabc = fabs((B-A)^(C-A));
	double Spab = fabs((A-P)^(B-P));
	double Spac = fabs((A-P)^(C-P));
	double Spbc = fabs((B-P)^(C-P));
	return dcmp(Sabc-Spab-Spac-Spbc)==0;
}
//判断点P在多边形内-射线法
bool InPolygon(Point P)
{
    bool flag = false;
    Point P1,P2; //多边形一条边的两个顶点
    for(int i=1,j=n;i<=n;j=i++)
    {
		//polygon[]是给出多边形的顶点
        P1 = polygon[i];
        P2 = polygon[j];
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
		//前一个判断min(P1.y,P2.y)<P.y<=max(P1.y,P2.y)
        if( (dcmp(P1.y-P.y)>0 != dcmp(P2.y-P.y)>0) && dcmp(P.x - (P.y-P1.y)*(P1.x-P2.x)/(P1.y-P2.y)-P1.x)<0)
            flag = !flag;
    }
    return flag;
}
typedef Point Vector;
