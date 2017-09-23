#include <bits/stdc++.h>
using namespace std;
typedef __int64 ll;

int dcmp(ll x)
{
    if(x==0) return 0;
    else if(x>0) return 1;
    else return -1;
}

struct Point{
	ll x,y;
    ll a,b,c,d;
	Point (){}
	Point(ll _x,ll _y)
	{
	    x = _x;
	    y = _y;
	    a=b=c=d=0;
	}

	//向量+
	Point operator +(const Point &b)const
	{
		return Point(x+b.x,y+b.y);
	}
	//向量-
	Point operator -(const Point &b)const
	{
		return Point(x-b.x,y-b.y);
	}
	//点积
	ll operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//叉积
	//P^Q>0,P在Q的顺时针方向；<0，P在Q的逆时针方向；=0，P，Q共线，可能同向或反向
	ll operator ^(const Point &b)const
	{
		return x*b.y - b.x*y;
	}
};
struct Frac{
    ll q,p;

    ll gcd(ll a,ll b)
    {
        while(b)
        {
            ll tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }

    void check(ll a,ll b)
    {
        ll tmp = gcd(a,b);
        a /= tmp;
        b /= tmp;
        q = a;
        p = b;
        if(p<0)
        {
            p = -p;
            q = -q;
        }
    }
};

bool IsPoint(Point a,Point b)
{
    if(a.x==b.x && a.y==b.y) return true;
    else return false;
}

//线段相交求交点 1代表相交 0代表不相交 -1代表交点无数
pair<int,Point> segment_intersect_point(Point P1,Point P2,Point P3,Point P4)
{
    Point ans;
    int k1,k2,k3,k4;
    ll s1,s2,s3,s4;
    k1 = dcmp(s1 = (P2-P1)^(P3-P1));
    k2 = dcmp(s2 = (P2-P1)^(P4-P1));
    k3 = dcmp(s3 = (P4-P3)^(P1-P3));
    k4 = dcmp(s4 = (P4-P3)^(P2-P3));

    //规范相交
    if(k1^k2==-2 && k3^k4==-2)
    {
        ans.a = s1*P4.x-s2*P3.x;
        ans.b = s1-s2;
        ans.c = s1*P4.y-s2*P3.y;
        ans.d = ans.b;
        return make_pair(1,ans);
    }
    ll mi1,mi2,mx1,mx2;
    if(P1.x!=P2.x)
    {
        mi1 = min(P1.x,P2.x);
        mx1 = max(P1.x,P2.x);
        mi2 = min(P3.x,P4.x);
        mx2 = max(P3.x,P4.x);
    }
    else
    {
        mi1 = min(P1.y,P2.y);
        mx1 = max(P1.y,P2.y);
        mi2 = min(P3.y,P4.y);
        mx2 = max(P3.x,P4.y);
    }
    if(k1==0 && k2==0 && k3==0 && k4==0)
    {
        if(mi2 < mi1 && mi1 < mx2 ||
           mi2 < mx1 && mx1 < mx2 ||
           mi1 < mi2 && mi2 < mx1 ||
           mi1 < mx2 && mx2 < mx1 ||
           mi2 <= mi1 && mx1 <= mx2 ||
           mi1 <= mi2 && mx2 <= mx1)
            return make_pair(-1,ans);
    }
    if(k1==0 && dcmp((P1-P3)*(P2-P3))<=0)
    {
        ans.a = P3.x;
        ans.c = P3.y;
        ans.b=ans.d=1;
        return make_pair(1,ans);
    }
    if(k2==0 && dcmp((P1-P4)*(P2-P4))<=0)
    {
        ans.a = P4.x;
        ans.c = P4.y;
        ans.b=ans.d=1;
        return make_pair(1,ans);
    }
    if(k3==0 && dcmp((P3-P1)*(P4-P1))<=0)
    {
        ans.a = P1.x;
        ans.c = P1.y;
        ans.b=ans.d=1;
        return make_pair(1,ans);
    }
    if(k4==0 && dcmp((P3-P2)*(P4-P2))<=0)
    {
        ans.a = P2.x;
        ans.c = P2.y;
        ans.b=ans.d=1;
        return make_pair(1,ans);
    }
    return make_pair(0,ans);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Point P1,P2,P3,P4;
        scanf("%I64d %I64d %I64d %I64d",&P1.x,&P1.y,&P2.x,&P2.y);
        scanf("%I64d %I64d %I64d %I64d",&P3.x,&P3.y,&P4.x,&P4.y);
        if(IsPoint(P1,P2))
        {
            if(IsPoint(P3,P4))
            {
                if(IsPoint(P1,P3))
                {
                    printf("1\n");
                    printf("%I64d %I64d\n",P1.x,P1.y);
                }
                else
                    printf("0\n");
            }
            else
            {
                if(dcmp((P3-P1)^(P4-P1))==0 && dcmp((P3-P1)*(P4-P1))<=0)
                {
                    printf("1\n");
                    printf("%I64d %I64d\n",P1.x,P1.y);
                }
                else
                    printf("0\n");
            }
        }
        else
        {
            if(IsPoint(P3,P4))
            {
                if(dcmp((P1-P3)^(P2-P3))==0 && dcmp((P1-P3)*(P2-P3))<=0)
                {
                    printf("1\n");
                    printf("I64d %I64d\n",P3.x,P3.y);
                }
                else
                    printf("0\n");
            }
            else
            {
                pair<int,Point> tmp = segment_intersect_point(P1,P2,P3,P4);
                if(tmp.first==0)
                    printf("0\n");
                else if(tmp.first==-1)
                    printf("INF\n");
                else
                {
                    Frac ans1,ans2;
                    ans1.check(tmp.second.a,tmp.second.b);
                    ans2.check(tmp.second.c,tmp.second.d);
                    printf("1\n");
                    if(ans1.p==1) printf("%I64d ",ans1.q);
                    else printf("%I64d/%I64d ",ans1.q,ans1.p);
                    if(ans2.p==1) printf("%I64d\n",ans2.q);
                    else printf("%I64d/%I64d\n",ans2.q,ans2.p);
                }
            }
        }
    }
    return 0;
}
