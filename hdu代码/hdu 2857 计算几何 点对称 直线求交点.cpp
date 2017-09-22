#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
//���P����ֱ��L�ĶԳƵ�
Point symmetry_point(Point P,Line L)
{
    Point ans = Point();
    ans.x = P.x-2*L.A*(L.A*P.x+L.B*P.y+L.C)/(L.A*L.A+L.B*L.B);
    ans.y = P.y-2*L.B*(L.A*P.x+L.B*P.y+L.C)/(L.A*L.A+L.B*L.B);
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Point X1,X2,Y1,Y2,tmp;
        scanf("%lf %lf",&X1.x,&X1.y);
        scanf("%lf %lf",&X2.x,&X2.y);
        scanf("%lf %lf",&Y1.x,&Y1.y);
        scanf("%lf %lf",&tmp.x,&tmp.y);
        Line L1 = Line(X1,X2);
        Y2 = symmetry_point(tmp,L1);
        Line L2 = Line(Y1,Y2);
        pair<int,Point> ans = L1&L2;
        printf("%.3f %.3f\n",fabs(ans.second.x)<0.001 ? 0 : ans.second.x,fabs(ans.second.y)<0.001 ? 0 : ans.second.y);
    }
    return 0;
}
