#include <bits/stdc++.h>
using namespace std;
int x, y;
int inf = 1e9;
double k1, k2;
double eps = 1e-7;
bool judge(int x, int xx)
{
    double value = (double)x / (double)xx;
    if(value - k1 >= eps && value - k2 < eps) return true;
    else return false;
}
int bi_search(int xx)
{
    int l = 1, r = inf;
    int re;
    while(l <= r)
    {
        int mid = (l + r)>>1;
        if(judge(mid, xx))
        {
            re = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return re;
}
int main()
{
    while(~scanf("%d%d", &x, &y))
    {
        if(x > y) cout<<"-1"<<endl;
        else
        {
            k1 = (double)y / (double)x;
            k2 = (double)(y + 1) / (double)x;
            cout<<"k1 == "<<k1<<endl;
            cout<<"k2 == "<<k2<<endl;
            int ans = 0;
            int sx = 1, sy = 1;
            while(sx < x)
            {
                int upy = bi_search(sx);
                cout<<"upy == "<<upy<<endl;
                ans += (upy - sy);
                sx++;
                double total = (double)sx * sy / (sx - 1);
                sy = (int)total;
                ans++;
            }
            if(sy < y) ans += (y - sy);
            printf("%d\n", ans);
        }
    }
    return 0;
}
