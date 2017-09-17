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
typedef Point Vector;
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
    return dcmp((P1-Q)^(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0;
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
//判断点P在多边形内-角度和判断法
//精度要求高 最好不用
bool InPolygon(Point P)
{
    double angle = 0;
    Point P1,P2; //多边形一条边的两个顶点
    Vector V1,V2; //以被测点为原点 P1 P2与P形成的向量
    for(int i=1,j=n;i<=n;j=i++)
    {
        P1 = polygon[i];
        P2 = polygon[j];
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
        V1 = P1-P;
        V2 = P2-P;
        double res = atan2(V2.y,V2.x)-atan2(V1.y,V1.x);
        res = abs(res);
        if(dcmp(res-PI)>0) res = 2*PI-res;
        angle += res;
    }
    return dcmp(2*PI-angle)==0;
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
//判断点P在多边形内-改进弧长法（多边形点顺时针给出）
//用这个还不如用上一个转角法
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
        if(g==2) dcmp(V1^V2)>0 ? (ans-=2) : (ans+=2); //在相对象限
    }
    return ans!=0;
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
//判断线段A1A2和线段B1B2是否相交
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
