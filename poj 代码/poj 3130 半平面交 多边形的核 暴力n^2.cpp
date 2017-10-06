#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define eps 1e-8
#define PI 3.14159265359
using namespace std;
typedef long long ll;

//��̬�������ж�����double��eps�����µĴ�С��ϵ
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}

	//����+
	Point operator +(const Point &b)const
	{
		return Point(x+b.x,y+b.y);
	}
	//����-
	Point operator -(const Point &b)const
	{
		return Point(x-b.x,y-b.y);
	}
	//���
	double operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//���
	//P^Q>0,P��Q��˳ʱ�뷽��<0��P��Q����ʱ�뷽��=0��P��Q���ߣ�����ͬ�����
	double operator ^(const Point &b)const
	{
		return x*b.y - b.x*y;
	}
	//�����ã�����x�������С�������x��ͬ����ô����y��С����
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
    //��ֱ���ཻ�󽻵�
    //��һ��ֵΪ0��ʾֱ���غϣ�Ϊ1��ʾƽ�У�Ϊ2���ཻ
    //ֻ�е�һ��ֵΪ2ʱ�������������
    pair<int,Point> operator &(const Line &b)const
    {
        Point ans = Point();
        if(dcmp((e-s)^(b.e-b.s)) == 0)
        {
            if(dcmp((b.e-s)^(b.e-b.s)) == 0)
                return make_pair(0,ans);//�غ�
            else
                return make_pair(1,ans);//ƽ��
        }
        ans.x = (B*b.C-b.B*C)/(A*b.B-b.A*B);
        ans.y = (b.A*C-A*b.C)/(A*b.B-b.A*B);
        return make_pair(2,ans);
    }
};

int n,m;
Point an[55],bn[55],cn[55];

void HalfPlaneIntersect(Line L)
{
    int num=0;
    for(int i=1;i<=m;i++)
    {
        if(dcmp(L.A*bn[i].x+L.B*bn[i].y+L.C)<=0) cn[++num] = bn[i];
        else
        {
            if(dcmp(L.A*bn[i-1].x+L.B*bn[i-1].y+L.C)<0) cn[++num] = (Line(bn[i-1],bn[i])&L).second;
            if(dcmp(L.A*bn[i+1].x+L.B*bn[i+1].y+L.C)<0) cn[++num] = (Line(bn[i+1],bn[i])&L).second;
        }
    }
    for(int i=1;i<=num;i++) bn[i] = cn[i];
    bn[0] = cn[num];
    bn[num+1] = cn[1];
    m=num;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
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
        if(m) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
