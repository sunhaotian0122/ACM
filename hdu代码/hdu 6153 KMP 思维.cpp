#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const int maxn = 1e6+5;

char str1[maxn],str2[maxn];
int len1,len2,Next[maxn];

void set_next()
{
    Next[0]=Next[1]=0;
    for(int i=1;i<len2;i++)
    {
        int tmp=Next[i];
        while(tmp && str2[i]!=str2[tmp]) tmp = Next[tmp];
        if(str2[i]==str2[tmp]) tmp++;
        Next[i+1]=tmp;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str1);
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        char tmp;
        for(int i=0;i<=len1/2;i++)
        {
            if(len1-i-1<=i) break;
            tmp = str1[i];
            str1[i] = str1[len1-i-1];
            str1[len1-i-1] = tmp;
        }
        for(int i=0;i<=len2/2;i++)
        {
            if(len2-i-1<=i) break;
            tmp = str2[i];
            str2[i] = str2[len2-i-1];
            str2[len2-i-1] = tmp;
        }
        set_next();
        ll ans=0;
        ll num=0;
        for(int i=0;i<len1;i++)
        {
            while(num&&str1[i]!=str2[num])
            {
                ans += ((num+1)*num/2)%mod;
                ans %= mod;
                num = Next[num];
            }
            if(str1[i]==str2[num]) num++;
        }
        while(num)
        {
            ans += ((num+1)*num/2)%mod;
            ans %= mod;
            num = Next[num];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
