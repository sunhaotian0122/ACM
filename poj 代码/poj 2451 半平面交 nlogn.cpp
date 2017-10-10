#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#define eps 1e-10
#define PI 3.14159265359
using namespace std;
typedef long long ll;

const int maxn = 3e4+5;

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
}P[maxn];
typedef Point Vector;
struct Line{
    Point s,e;
    double A,B,C;
    double angle;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        A = e.y-s.y;
        B = s.x-e.x;
        C = e^s;
        angle = atan2(e.y-s.y,e.x-s.x);
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
    //��ƽ�潻��������
    bool operator <(const Line &b)const
    {
        int d = dcmp(angle-b.angle);
        if(d==0) //>0ȡƽ�����Ϊ��ƽ�� <0ȡ�Ұ�
            return dcmp((b.s-s)^(b.e-s)) > 0;
        else
            return d<0;
    }
}L[maxn];

int dq[maxn],top,tal;
int n;

//��ƽ�潻���������� nlogn
//�԰�ƽ��ȡֱ�����Ϊ��
bool check(Line L0,Line L1,Line L2)
{
    Point tmp = (L1&L2).second;
    return dcmp((L0.s-tmp)^(L0.e-tmp)) < 0;
    //�������Զ����<��ķ����෴
}

void HalfPlaneIntersect()
{
    sort(L+1,L+1+n);
    int num=1;
    for(int i=2;i<=n;i++)
    {
        if(dcmp(L[i].angle-L[num].angle)>0)
            L[++num]=L[i];
    }
    dq[0] = 1, dq[1] = 2;
    top = 1, tal = 0;
    for(int i=3;i<=num;i++)
    {
        while(top>tal && check(L[i],L[dq[top]],L[dq[top-1]])) top--;
        while(top>tal && check(L[i],L[dq[tal]],L[dq[tal+1]])) tal++;
        dq[++top] = i;
    }
    while(top>tal && check(L[dq[tal]],L[dq[top]],L[dq[top-1]])) top--;
    while(top>tal && check(L[dq[top]],L[dq[tal]],L[dq[tal+1]])) tal++;
    dq[++top] = dq[tal];
    n = 0;
    for(int i=tal;i<top;i++)
    {
        P[++n] = (L[dq[i]]&L[dq[i+1]]).second;
    }
    P[++n] = P[1];
}

double PolygonArea()
{
    if(n<3)
        return 0;
    double res = 0;
    for(int i=1;i<=n;i++)
    {
        res += P[i]^P[i+1];
    }
    if(dcmp(res)<0) res = -res;
    res /= 2.0;
    return res;
}

int main()
{
    while(~scanf("%d",&n))
    {
        Point a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
            L[i] = Line(a,b);
        }
        a.x=0,a.y=0,b.x=10000,b.y=0,L[n+1]=Line(a,b);
        a.x=10000,a.y=0,b.x=10000,b.y=10000,L[n+2]=Line(a,b);
        a.x=10000,a.y=10000,b.x=0,b.y=10000,L[n+3]=Line(a,b);
        a.x=0,a.y=10000,b.x=0,b.y=0,L[n+4]=Line(a,b);
        n += 4;
        HalfPlaneIntersect();
        printf("%.1f\n",PolygonArea());
    }
    return 0;
}
