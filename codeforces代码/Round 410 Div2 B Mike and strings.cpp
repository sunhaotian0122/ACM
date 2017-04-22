#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
char str[55][105],sz[55];
int next[55],len1,len2;

void set_next()
{
    next[0]=next[1]=0;
    for(int i=1;i<len2;i++)
    {
        int tmp=next[i];
        while(tmp && sz[i]!=sz[tmp]) tmp = next[tmp];
        if(sz[i]==sz[tmp]) tmp++;
        next[i+1]=tmp;
    }
}

int kmp(int x)
{
    set_next();
    bool flag=false;
    int num=0;
    for(int i=0;i<len1;i++)
    {
        while(num && str[x][i]!=sz[num]) num=next[num];
        if(str[x][i]==sz[num]) num++;
        if(num==len2)
        {
            flag=true;
            return i-len2+1;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str[i]);
        if(i==1) len2 = strlen(str[1]);
        for(int j=len2;j<2*len2;j++)
        {
            str[i][j] = str[i][j-len2];
        }
        str[i][2*len2] = '\0';
    }
    len1 = strlen(str[1]);
    int ans = INF;
    for(int i=0;i<len2;i++)
    {
        for(int j=i,k=0;j<len2+i;j++,k++)
        {
            sz[k] = str[1][j];
        }
        int tmp=0;
        set_next();
        for(int j=1;j<=n;j++)
        {
            if(kmp(j)!=-1) tmp += kmp(j);
            else
            {
                printf("-1\n");
                return 0;
            }
        }
        ans = min(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}
