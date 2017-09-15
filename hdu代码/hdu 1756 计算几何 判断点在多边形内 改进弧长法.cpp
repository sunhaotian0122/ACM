#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
const double PI = acos(-1);

int n,m;

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
}polygon[105];
typedef Point Vector;

//��̬�������ж�����double��eps�����µĴ�С��ϵ
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}

//�жϵ�Q�Ƿ���P1��P2���߶���
bool OnSegment(Point P1,Point P2,Point Q)
{
    return dcmp((P1-Q)^(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0;
}

//�жϵ�P�ڶ������-�Ľ�������
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
        if(g==1) ans--; //����һ����
        if(g==3) ans++; //����һ����
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
