#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans,tmp;
    string str;
    bool flag;
    while(~scanf("%d",&n))
    {
        flag=true;
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            cin>>tmp>>str;
            if(ans==0)
            {
                if(str=="South")
                {
                    ans += tmp;
                    if(ans>20000 || ans<0) flag=false;
                }
                else flag=false;
            }
            else if(ans==20000)
            {
                if(str=="North")
                {
                    ans -= tmp;
                    if(ans>20000 || ans<0) flag=false;
                }
                else flag=false;
            }
            else
            {
                if(str=="South")
                {
                    ans += tmp;
                    if(ans>20000 || ans<0) flag=false;
                }
                if(str=="North")
                {
                    ans -= tmp;
                    if(ans>20000 || ans<0) flag=false;
                }
            }
        }
        if(flag&&ans==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
