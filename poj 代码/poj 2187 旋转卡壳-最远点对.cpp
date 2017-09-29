#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 5e4+5;
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
        return y<b.y||(y==b.y&&x<b.x);
    }
}P[maxn];

int n,cv[maxn],num;

//��������֮��ľ���
double point_dis(Point a,Point b)
{
    return (a-b)*(a-b);
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&P[i].x,&P[i].y);
    }
    Graham();
    printf("%.0f\n",rotating_calipers());
    return 0;
}
