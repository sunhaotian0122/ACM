#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2500+10;
char str1[maxn],str2[maxn];
int len1,len2;
bool dp[maxn][maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str1);
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<len2;i++)
        {
            if(str2[i]=='*')
            {
                dp[i+1][0]=true;
                break;
            }
            if(str2[i]!=str2[i-1]) break;
        }
        for(int i=1;i<=len2;i++)
        {
            for(int j=1;j<=len1;j++)
            {
                if(str2[i-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else if(str2[i-1]=='*')
                    dp[i][j] = dp[i-1][j] || (dp[i-1][j-1]&&(str1[j-1]==str1[j-2])) || (dp[i][j-1]&&(str1[j-1]==str1[j-2])) || dp[i-2][j];
                else
                    dp[i][j] = dp[i-1][j-1] && (str1[j-1]==str2[i-1]);
            }
        }
        printf("%s",dp[len2][len1] ? "yes\n" : "no\n");
    }
    return 0;
}
