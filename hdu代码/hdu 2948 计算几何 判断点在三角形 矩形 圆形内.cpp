#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
const double PI = acos(-1);
const int maxn = 1e3+5;

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

struct Triangle{
    Point A,B,C;
}triangle[maxn];

struct Circle{
    Point O;
    double R;
}circle[maxn];

struct rectangle{
    Point A,B;
}rectangle[maxn];

//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
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
//判断点P是否在O为圆心R为半径的圆上
bool InCircle(Point O,double R,Point P)
{
    double pr = sqrt(pow(P.x-O.x,2)+pow(P.y-O.y,2));
    return dcmp(pr-R)<=0;
}
//判断点P是否在A，B为对顶点的矩形上
bool InRectangle(Point A,Point B,Point P)
{
    return (dcmp(P.x-A.x)>=0&&dcmp(P.y-A.y)>=0&&dcmp(P.x-B.x)<=0&&dcmp(P.y-B.y)<=0);
}

int main()
{
    int t,triangle_num=0,circle_num=0,rectangle_num=0;
    char str[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        switch(str[0])
        {
        case 'C':
            scanf("%lf %lf %lf",&circle[circle_num].O.x,&circle[circle_num].O.y,&circle[circle_num].R);
            circle_num++;
            break;
        case 'R':
            scanf("%lf %lf %lf %lf",&rectangle[rectangle_num].A.x,&rectangle[rectangle_num].A.y,&rectangle[rectangle_num].B.x,&rectangle[rectangle_num].B.y);
            rectangle_num++;
            break;
        case 'T':
            scanf("%lf %lf %lf %lf %lf %lf",&triangle[triangle_num].A.x,&triangle[triangle_num].A.y,&triangle[triangle_num].B.x,&triangle[triangle_num].B.y,&triangle[triangle_num].C.x,&triangle[triangle_num].C.y);
            triangle_num++;
            break;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        int ans1=0,ans2=0;
        Point tmp;
        for(int i=1;i<=3;i++)
        {
            scanf("%lf %lf",&tmp.x,&tmp.y);
            for(int j=0;j<triangle_num;j++)
                if(InTriangle(triangle[j].A,triangle[j].B,triangle[j].C,tmp)) ans1++;
            for(int j=0;j<rectangle_num;j++)
                if(InRectangle(rectangle[j].A,rectangle[j].B,tmp)) ans1++;
            for(int j=0;j<circle_num;j++)
                if(InCircle(circle[j].O,circle[j].R,tmp)) ans1++;
        }
        for(int i=1;i<=3;i++)
        {
            scanf("%lf %lf",&tmp.x,&tmp.y);
            for(int j=0;j<triangle_num;j++)
                if(InTriangle(triangle[j].A,triangle[j].B,triangle[j].C,tmp)) ans2++;
            for(int j=0;j<rectangle_num;j++)
                if(InRectangle(rectangle[j].A,rectangle[j].B,tmp)) ans2++;
            for(int j=0;j<circle_num;j++)
                if(InCircle(circle[j].O,circle[j].R,tmp)) ans2++;
        }
        if(ans1==ans2) printf("Tied\n");
        else printf("%s\n",ans1<ans2 ? "Hannah" : "Bob");
    }
    return 0;
}
