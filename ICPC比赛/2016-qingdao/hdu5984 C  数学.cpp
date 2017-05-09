#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    double l,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&l,&d);
        if(l<=d) printf("0.000000\n");
        else printf("%.6lf\n",log(l/d)+1);
    }
    return 0;
}
