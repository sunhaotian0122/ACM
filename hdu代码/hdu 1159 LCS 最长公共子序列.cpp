#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;
char str1[maxn],str2[maxn];
int ans[maxn][maxn];

void lcs()
{
    int len1=strlen(str1),len2=strlen(str2);
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1]) ans[i][j]=ans[i-1][j-1]+1;
            else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
        }
    }
    printf("%d\n",ans[len1][len2]);
}

int main()
{
    while(~scanf("%s %s",str1,str2))
    {
        lcs();
    }
    return 0;
}
