#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e3+5;
char str[maxn];
int len,m,ans;

void solve(int x,int y)
{
    int dis=0,l=0,r=0;
    while(x-r>=0 && y+r<len)
    {
        if(dis+abs(str[x-r]-str[y+r])<=m)
        {
            dis += abs(str[x-r]-str[y+r]);
            r++;
            ans = max(ans,r-l);
        }
        else
        {
            dis -= abs(str[x-l]-str[y+l]);
            l++;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        scanf("%s",str);
        len = strlen(str);
        ans = 0;
        for(int i=0;i<len;i++)
        {
            solve(i-1,i+1);
            solve(i,i+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
