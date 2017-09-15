#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;
const double PI = acos(-1);

const int maxn = 1e5+5;
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
}polygon[maxn];
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

//�жϵ�P�ڶ������-O(logn) ˳ʱ�����
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

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%lf %lf",&polygon[i].x,&polygon[i].y);
        Point test;
        bool flag = true;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%lf %lf",&test.x,&test.y);
            if(!flag) continue;
            if(!InPolygon(test)) flag = false;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
