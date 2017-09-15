#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-8;
const double PI = acos(-1);

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
}P1[5],P2[5],V1,V2;
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

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        for(int i=1;i<=3;i++) scanf("%lf %lf",&P1[i].x,&P1[i].y);
        scanf("%lf %lf",&V1.x,&V1.y);
        for(int i=1;i<=3;i++) scanf("%lf %lf",&P2[i].x,&P2[i].y);
        scanf("%lf %lf",&V2.x,&V2.y);
        //��P1Ϊ�ο�ϵ
        Vector V = V2-V1;
        bool flag = false;
        for(int k=1;k<=3;k++)
        {
            Point P = P2[k];
            for(int i=1,j=3;i<=3;j=i++)
            {
                Vector S1 = P1[i]-P1[j];
                Vector S2 = P-P1[j];
                if(dcmp(S1^V)==0)
                {
                    if(OnSegment(P1[i],P1[j],P))
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if(dcmp((S2^S1)/(S1^V))<0) continue;
                    Vector S3;
                    S3.x = -S2.x-(S2^S1)*V.x/(S1^V);
                    S3.y = -S2.y-(S2^S1)*V.y/(S1^V);
                    if(dcmp((S1+S3)*S3)<=0)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag) printf("Case #%d: YES\n",ca);
        else printf("Case #%d: NO\n",ca);
    }
    return 0;
}
