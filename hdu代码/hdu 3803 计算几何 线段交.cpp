#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-8;
const double PI = acos(-1);

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

//��̬�������ж�����double��eps�����µĴ�С��ϵ
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}
struct Point{
	double x,y;
	double a,b,c,d;

	Point (){}
	Point(double _x,double _y)
	{
	    x = _x;
	    y = _y;
	    a=b=c=d=0;
	}

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
        ans.a = B*b.C-b.B*C;
        ans.b = A*b.B-b.A*B;
        ans.c = b.A*C-A*b.C;
        ans.d = A*b.B-b.A*B;
        return make_pair(2,ans);
    }
};
//�ж��߶�A1A2���߶�B1B2�Ƿ��ཻ
bool Segment_Intersect(Point A1,Point A2,Point B1,Point B2)
{
    if(max(A1.x,A2.x)>=min(B1.x,B2.x) &&
       max(B1.x,B2.x)>=min(A1.x,A2.x) &&
       max(A1.y,A2.y)>=min(B1.y,B2.y) &&
       max(B1.y,B2.y)>=min(A1.y,A2.y) && //�����ų�ʵ��
       dcmp(((B1-A1)^(A2-A1))*((A1-B2)^(A2-A1)))>=0 && //����ʵ��
       dcmp(((A1-B1)^(B2-B1))*((B1-A2)^(B2-B1)))>=0)
       return true;
    else return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Point P1,P2,P3,P4;
        scanf("%lf %lf %lf %lf",&P1.x,&P1.y,&P2.x,&P2.y);
        scanf("%lf %lf %lf %lf",&P3.x,&P3.y,&P4.x,&P4.y);
        if(!Segment_Intersect(P1,P2,P3,P4))
        {
            printf("0\n");
            continue;
        }
        Line L1 = Line(P1,P2),L2 = Line(P3,P4);
        pair<int,Point> ans = L1&L2;
        if(ans.first==0)
        {
            printf("INF\n");
        }
        else
        {
            printf("1\n");
            int a,b,c,d;
            a = (int)ans.second.a;
            b = (int)ans.second.b;
            c = (int)ans.second.c;
            d = (int)ans.second.d;
            if(a*b<0)
            {
                a = abs(a);
                b = abs(b);
                int tmp = gcd(a,b);
                a /= tmp;
                b /= tmp;
                if(b>1) printf("-%d/%d ",a,b);
                else printf("-%d ",a);
            }
            else
            {
                a = abs(a);
                b = abs(b);
                int tmp = gcd(a,b);
                a /= tmp;
                b /= tmp;
                if(b>1) printf("%d/%d ",a,b);
                else printf("%d ",a);
            }
            if(c*d<0)
            {
                c = abs(c);
                d = abs(d);
                int tmp = gcd(c,d);
                c /= tmp;
                d /= tmp;
                if(d>1) printf("-%d/%d\n",c,d);
                else printf("-%d\n",c);
            }
            else
            {
                c = abs(c);
                d = abs(d);
                int tmp = gcd(c,d);
                c /= tmp;
                d /= tmp;
                if(d>1) printf("%d/%d\n",c,d);
                else printf("%d\n",c);
            }
        }
    }
    return 0;
}
