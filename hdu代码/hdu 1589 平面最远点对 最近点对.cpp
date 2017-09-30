#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e4+5;
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

int n,cv[maxn],num,sz[maxn];

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

//͹�� Graham-Scan O(nlogn)
//��������
bool cmp(Point a,Point b)
{
    double tmp = (a-P[1])^(b-P[1]);
    if(dcmp(tmp)>0) return true;
    else if(dcmp(tmp)==0 && dcmp(point_dis(P[1],a)-point_dis(P[1],b))<0) return true;
    else return false;
}
void Graham()
{
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(dcmp(P[i].y-P[k].y)<0 || (dcmp(P[i].y-P[k].y)==0 && dcmp(P[i].x-P[k].x)<0))
            k = i;
    }
    if(k!=1) swap(P[1],P[k]);
    sort(P+2,P+n+1,cmp);
    if(n==1)
    {
        num=1;
        cv[1]=1;
        return;
    }
    if(n==2)
    {
        num=2;
        cv[1]=1;
        cv[2]=2;
        return;
    }
    num=2;
    cv[1]=1;
    cv[2]=2;
    for(int i=3;i<=n;i++)
    {
        while(num>1 && dcmp((P[cv[num]]-P[cv[num-1]])^(P[i]-P[cv[num-1]]))<=0)
            num--;
        cv[++num]=i;
    }
}
//��ת����-��Զ���
//����͹�� P[]Ϊԭ������ cv[]Ϊ͹��������(��ʱ��) numΪ�����
double rotating_calipers()
{
    double ans = 0;
    int j=2;
    cv[num+1] = cv[1];
    for(int i=1;i<=num;i++)
    {
        while(dcmp(((P[cv[i+1]]-P[cv[i]])^(P[cv[j+1]]-P[cv[i]]))-((P[cv[i+1]]-P[cv[i]])^(P[cv[j]]-P[cv[i]]))>0))
        {
            j++;
            if(j>num) j=1;
        }
        ans = max(ans,point_dis(P[cv[i]],P[cv[j]]));
    }
    return ans;
}

int main()
{
    int ca=1;
    while(~scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&P[i].x,&P[i].y);
        sort(P+1,P+1+n);
        double pmin = closest_point(1,n);
        Graham();
        double pmax = rotating_calipers();
        printf("Case %d:\n",ca++);
        printf("Distance of the nearest couple is %.3f\n",pmin);
        printf("Distance of the most distant couple is %.3f\n\n",pmax);
    }
    return 0;
}
