#include<bits/stdc++.h>
using namespace std;
const double eps=1e-3;
int main()
{
    double x,y;
    while(~scanf("%lf%lf",&x,&y))
    {
        if(x>y)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int ans=0;
        double k=(y-eps+1)/x;
        double xx=1,yy=1;
        for(int i=0;i<int(x);i++)
        {
            if(k-(yy+1)/xx>=eps)
                yy++;
            else
            {
                double kk=yy/xx;
                xx++;
                yy=xx*kk;
            }
            cout<<xx<<" "<<yy<<endl;
            ans++;
        }
        ans+=(int(y)-int(yy));
        cout<<ans<<endl;
    }
    return 0;
}
