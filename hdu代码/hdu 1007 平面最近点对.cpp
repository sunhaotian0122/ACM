#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
const double INF = 1e20;
const double eps = 1e-8;
const double PI = acos(-1);

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

int n,sz[maxn];

//��������֮��ľ���
double point_dis(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}

//ƽ�������� O(nlogn)
//����
bool cmpy(int a,int b)
{
    return P[a].y<P[b].y;
}
//����
double closest_point(int l,int r)
{
    double d = INF;
    if(l==r) return d;
    if(l+1==r) return point_dis(P[l],P[r]);
    int mid = (l+r)>>1;
    d = min(closest_point(l,mid),closest_point(mid+1,r));
    int k=0;
    for(int i=l;i<=r;i++)
    {
        if(fabs(P[i].x-P[mid].x)<d) sz[++k] = i;
    }
    sort(sz+1,sz+1+k,cmpy);
    for(int i=1;i<k;i++)
    {
        for(int j=i+1;j<=k;j++)
        {
            if(P[sz[j]].y-P[sz[i]].y>=d) break;
            double tmp = point_dis(P[sz[i]],P[sz[j]]);
            if(dcmp(tmp-d)<0) d = tmp;
        }
    }
    return d;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&P[i].x,&P[i].y);
        sort(P+1,P+1+n);
        double pmin = closest_point(1,n);
        printf("%.2f\n",pmin/2.0);
    }
    return 0;
}
