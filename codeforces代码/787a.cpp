#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void ex_gcd(int a,int b,int& d,int& x,int & y)
{
	if(!b) {d = a; x = 1; y = 0; }
	else {ex_gcd(b, a%b, d, y, x); y -= x*(a/b); }
}


int main()
{
    int a,b,c,d,ans,x,y,g,minx,k1,k2,miny;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&c,&d);
    ex_gcd(a,-c,g,x,y);
    if((d-b)%g==0)
    {
        minx = x*(d-b)/g;
        miny = y*(d-b)/g;
        k1 = (-c)/g;
        if(k1<0) k1 = -k1;
        k2 = a/g;
        if(k2<0) k2 = -k2;
        minx = (minx%k1+k1)%k1;
        miny = (miny%k2+k2)%k2;
        if(a*minx+b-d>=0)
        {
            ans = a*minx+b;
            printf("%d\n",ans);
        }
        else
        {
            ans = c*miny+d;
            printf("%d\n",ans);
        }
        /*cout<<g<<endl;
        cout<<x<<" "<<y<<endl;
        cout<<minx<<endl;*/
    }
    else printf("-1\n");
    return 0;
}
