#include <cstdio>
#include <cstring>
using namespace std;

char str1[1005],str2[1005];
int next[1005];

void set_next()
{
    next[0]=next[1]=0;
    for(int i=1;i<strlen(str2);i++)
    {
        int tmp=next[i];
        while(tmp && str2[i]!=str2[tmp]) tmp=next[tmp];
        if(str2[i]==str2[tmp]) tmp++;
        next[i+1]=tmp;
    }
}

int main()
{
    while(scanf("%s",str1)&&str1[0]!='#')
    {
        scanf("%s",str2);
        set_next();
        int num=0,ans=0;
        for(int i=0;i<strlen(str1);i++)
        {
            while(num && str1[i]!=str2[num]) num = next[num];
            if(str1[i]==str2[num]) num++;
            if(num==strlen(str2))
            {
                ans++;
                num=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
