#define eps 1e-8
#define PI 3.14159265359

//三态函数，判断两个double在eps精度下的大小关系
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else
        return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	
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
	//P*Q>0 P与Q成锐角 <0为钝角 =0为直角
	double operator *(const Point &b)const
	{
		return x*b.x + y*b.y;
	}
	//叉积
	//P^Q>0,P在Q的顺时针方向；<0，P在Q的逆时针方向；=0，P，Q共线，可能同向或反向
	double operator ^(const Point &b)const
	{
		return x*b.y - b.x*y;
	}
	//排序用，按照x的坐标从小到大，如果x相同，那么按照y从小到大
    bool operator <(const Point &b)const
    {
        return x<b.x||(x==b.x&&y<b.y);
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
    //两直线相交求交点
    //第一个值为0表示直线重合，为1表示平行，为2是相交
    //只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point ans = Point();
        if(dcmp((e-s)^(b.e-b.s)) == 0)
        {
            if(dcmp((b.e-s)^(b.e-b.s)) == 0)
                return make_pair(0,ans);//重合
            else
                return make_pair(1,ans);//平行
        }
        ans.x = (B*b.C-b.B*C)/(A*b.B-b.A*B);
        ans.y = (b.A*C-A*b.C)/(A*b.B-b.A*B);
        return make_pair(2,ans);
    }
	//半平面交极角排序
    bool operator <(const Line &b)const
    {
        int d = dcmp(angle-b.angle);
        if(d==0) //>0取平面左半为半平面 <0取右半
            return dcmp((b.s-s)^(b.e-s)) > 0;
        else
            return d<0;
    }
};
//求点P关于直线L的对称点
Point symmetry_point(Point P,Line L)
{
    Point ans = Point();
    ans.x = P.x-2*L.A*(L.A*P.x+L.B*P.y+L.C)/(L.A*L.A+L.B*L.B);
    ans.y = P.y-2*L.B*(L.A*P.x+L.B*P.y+L.C)/(L.A*L.A+L.B*L.B);
    return ans;
}
//计算两点之间的距离
double point_dis(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
//判断点Q是否在P1和P2的直线上
bool OnBeeline(Point P1,Point P2,Point Q)
{
	return dcmp((P1-Q)^(P2-Q))==0;
}
//判断点Q是否在P1和P2的线段上
bool OnSegment(Point P1,Point P2,Point Q)
{
    return dcmp((P1-Q)^(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0;
}
//判断点P是否在三角形ABC中
bool InTriangle(Point A,Point B,Point C,Point P)
{
	double Sabc = fabs((B-A)^(C-A));
	double Spab = fabs((A-P)^(B-P));
	double Spac = fabs((A-P)^(C-P));
	double Spbc = fabs((B-P)^(C-P));
	return dcmp(Sabc-Spab-Spac-Spbc)==0;
}
//判断凸多边形poly[n] 允许共线边 点顺逆均可
bool isconvex()
{
    bool s[3];
    memset(s,false,sizeof(s));
    for(int i=0;i<n;i++)
    {
        s[dcmp((poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i])) + 1] = true;
        if(s[0] && s[2]) return false;
    }
    return true;
}
//多边形面积
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
//判断点P在多边形内-射线法
bool InPolygon(Point P)
{
    bool flag = false;
    Point P1,P2; //多边形一条边的两个顶点
    for(int i=1,j=n;i<=n;j=i++)
    {
		//polygon[]是给出多边形的顶点
        P1 = polygon[i];
        P2 = polygon[j];
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
		//前一个判断min(P1.y,P2.y)<P.y<=max(P1.y,P2.y)
        if( (dcmp(P1.y-P.y)>0 != dcmp(P2.y-P.y)>0) && dcmp(P.x - (P.y-P1.y)*(P1.x-P2.x)/(P1.y-P2.y)-P1.x)<0)
            flag = !flag;
    }
    return flag;
}
//判断点P在多边形内-角度和判断法
//精度要求高 最好不用
bool InPolygon(Point P)
{
    double angle = 0;
    Point P1,P2; //多边形一条边的两个顶点
    Vector V1,V2; //以被测点为原点 P1 P2与P形成的向量
    for(int i=1,j=n;i<=n;j=i++)
    {
        P1 = polygon[i];
        P2 = polygon[j];
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
        V1 = P1-P;
        V2 = P2-P;
        double res = atan2(V2.y,V2.x)-atan2(V1.y,V1.x);
        res = abs(res);
        if(dcmp(res-PI)>0) res = 2*PI-res;
        angle += res;
    }
    return dcmp(2*PI-angle)==0;
}
//判断点P在多边形内-转角法（多边形点顺时针给出）
bool InPolygon(Point P)
{
    int wn = 0;
    Point P1,P2; //多边形一条边的两个顶点
    Vector V1,V2; //被测点与P1分别于P2形成的向量
    for(int i=1,j=n;i<=n;j=i++)
    {
        P1 = polygon[j];  //顺时针中前一点
        P2 = polygon[i];  //顺时针中后一点
        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
        V1 = P2-P1;
        V2 = P-P1;
        int k = dcmp(V1^V2);
        int d1 = dcmp(P1.y-P.y);
        int d2 = dcmp(P2.y-P.y);
        if(k>0 && d1<=0&&d2>0) wn--;  //测试点在有向边左边 有向边向上穿过
        if(k<0 && d1>0&&d2<=0) wn++;  //测试点在有向边右边 有向边向下穿过
    }
    return wn!=0;
}
//判断点P在多边形内-改进弧长法（多边形点顺时针给出）
//用这个还不如用上一个转角法
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
        if(g==1) ans--; //在上一象限
        if(g==3) ans++; //在下一象限
        if(g==2) dcmp(V1^V2)>0 ? (ans-=2) : (ans+=2); //在相对象限
    }
    return ans!=0;
}
//判断点P在多边形内-O(logn) 顺时针给出
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
//判断线段A1A2和线段B1B2是否相交
bool Segment_Intersect(Point A1,Point A2,Point B1,Point B2)
{
    if(max(A1.x,A2.x)>=min(B1.x,B2.x) &&
       max(B1.x,B2.x)>=min(A1.x,A2.x) &&
       max(A1.y,A2.y)>=min(B1.y,B2.y) &&
       max(B1.y,B2.y)>=min(A1.y,A2.y) && //快速排斥实验
       dcmp(((B1-A1)^(A2-A1))*((A1-B2)^(A2-A1)))>=0 && //跨立实验
       dcmp(((A1-B1)^(B2-B1))*((B1-A2)^(B2-B1)))>=0)
       return true;
    else return false;
}
//判断P1P2与P3P4线段(不能是点)相交并求交点 1代表相交 0代表不相交 -1代表交点无数
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
    if((k1^k2)==-2 && (k3^k4)==-2)
    {
        ans.x = (s1*P4.x-s2*P3.x)/s1-s2;
        ans.y = (s1*P4.y-s2*P3.y)/s1-s2;
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
        ans.x = P3.x;
        ans.y = P3.y;
        return make_pair(1,ans);
    }
    if(k2==0 && dcmp((P1-P4)*(P2-P4))<=0)
    {
        ans.x = P4.x;
        ans.y = P4.y;
        return make_pair(1,ans);
    }
    if(k3==0 && dcmp((P3-P1)*(P4-P1))<=0)
    {
        ans.x = P1.x;
        ans.y = P1.y;
        return make_pair(1,ans);
    }
    if(k4==0 && dcmp((P3-P2)*(P4-P2))<=0)
    {
        ans.x = P2.x;
        ans.y = P2.y;
        return make_pair(1,ans);
    }
    return make_pair(0,ans);
}
//凸包 Jarvis步进法 O(nh) 
void Jarvis()
{
    sort(polygon+1,polygon+n+1);
    cnt=num=0;
	//右链
    sta[cnt++]=1,sta[cnt++]=2;
    for(int i=3;i<=n;i++)
    {
        while(cnt>1 && dcmp((polygon[i]-polygon[sta[cnt-2]])^(polygon[sta[cnt-1]]-polygon[sta[cnt-2]]))>=0)
            cnt--;
        sta[cnt++]=i;
    }
    for(int i=0;i<cnt;i++) convex_hull[++num]=sta[i];
	//左链
    cnt=0,sta[cnt++]=n,sta[cnt++]=n-1;
    for(int i=n-2;i>=1;i--)
    {
        while(cnt>1 && dcmp((polygon[i]-polygon[sta[cnt-2]])^(polygon[sta[cnt-1]]-polygon[sta[cnt-2]]))>=0)
            cnt--;
        sta[cnt++]=i;
    }
    for(int i=0;i<cnt;i++) convex_hull[++num]=sta[i];
}
//凸包 Graham-Scan O(nlogn)
//极角排序
bool cmp(Point a,Point b)
{
    double tmp = (a-polygon[1])^(b-polygon[1]);
    if(dcmp(tmp)>0) return true;
    else if(dcmp(tmp)==0 && dcmp(point_dis(polygon[1],a)-point_dis(polygon[1],b))<0) return true;
    else return false;
}
void Graham()
{
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(dcmp(polygon[i].y-polygon[k].y)<0 || (dcmp(polygon[i].y-polygon[k].y)==0 && dcmp(polygon[i].x-polygon[k].x)<0))
            k = i;
    }
    if(k!=1) swap(polygon[1],polygon[k]);
    sort(polygon+2,polygon+n+1,cmp);
    if(n==1)
    {
        num=1;
        convex_hull[1]=1;
        return;
    }
    if(n==2)
    {
        num=2;
        convex_hull[1]=1;
        convex_hull[2]=2;
        return;
    }
    num=2;
    convex_hull[1]=1;
    convex_hull[2]=2;
    for(int i=3;i<=n;i++)
    {
        while(num>1 && dcmp((polygon[convex_hull[num]]-polygon[convex_hull[num-1]])^(polygon[i]-polygon[convex_hull[num-1]]))<=0)
            num--;
        convex_hull[++num]=i;
    }
}
//旋转卡壳-最远点对
//先求凸包 P[]为原给出点 cv[]为凸包顶点编号(逆时针) num为其个数
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
//平面最近点对 O(nlogn)
//P[]为给出点集 先以按横坐标排序
//排序
bool cmpy(int a,int b)
{
    return P[a].y<P[b].y;
}
//分治
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
//半平面交排序增量法 nlogn
//以半平面取直线左半为例
bool check(Line L0,Line L1,Line L2)
{
    Point tmp = (L1&L2).second;
    return dcmp((L0.s-tmp)^(L0.e-tmp)) < 0;
    //与上面自定义的<里的符号相反
}
//直线存在L[1-n]中 取左半为半平面
//最后形成的有效交点存在P[1-n]中
//dq[]模仿双端队列
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
//半平面交n^2算法
//以取平面右半为例
//对每一条直线都要切割一次
void HalfPlaneIntersect(Line L)
{
    int num=0;
    for(int i=1;i<=m;i++)
    {
		//点在右半加入有效点
        if(dcmp(L.A*bn[i].x+L.B*bn[i].y+L.C)<=0) cn[++num] = bn[i];
        else
        {
			//在左半就判断i-1和i+1点在不在右半 在就取交点
            if(dcmp(L.A*bn[i-1].x+L.B*bn[i-1].y+L.C)<0) cn[++num] = (Line(bn[i-1],bn[i])&L).second;
            if(dcmp(L.A*bn[i+1].x+L.B*bn[i+1].y+L.C)<0) cn[++num] = (Line(bn[i+1],bn[i])&L).second;
        }
    }
    for(int i=1;i<=num;i++) bn[i] = cn[i];
    bn[0] = cn[num];
    bn[num+1] = cn[1];
    m=num;
}