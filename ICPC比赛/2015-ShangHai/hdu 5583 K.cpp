#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
char str[maxn];
ll sz[maxn];

int main()
{
    int t,i,j;
    ll k,ans,tmp;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%s",str);
        for(i=1,j=1,k=1,tmp=0;str[i]!='\0';i++)
        {
            if(str[i]!=str[i-1])
            {
                sz[j++] = k;
                tmp += k*k;
                k=1;
            }
            else k++;
        }
        sz[j++]=k,tmp+=k*k,ans=tmp;
        sz[j]=0;
        for(i=1;i<j-1;i++)
        {
            if(sz[i+1]==1)
                ans = max(ans,tmp-sz[i]*sz[i]-sz[i+1]*sz[i+1]-sz[i+2]*sz[i+2]+(sz[i]+sz[i+1]+sz[i+2])*(sz[i]+sz[i+1]+sz[i+2]));
            else
                ans = max(ans,tmp-sz[i]*sz[i]-sz[i+1]*sz[i+1]+(sz[i]+1)*(sz[i]+1)+(sz[i+1]-1)*(sz[i+1]-1));
            if(sz[i]==1)
                ans = max(ans,tmp-sz[i-1]*sz[i-1]-sz[i]*sz[i]-sz[i+1]*sz[i+1]+(sz[i-1]+sz[i]+sz[i+1])*(sz[i-1]+sz[i]+sz[i+1]));
            else
                ans = max(ans,tmp-sz[i]*sz[i]-sz[i+1]*sz[i+1]+(sz[i]-1)*(sz[i]-1)+(sz[i+1]+1)*(sz[i+1]+1));
        }
        printf("Case #%d: %lld\n",ca,ans);
    }
    return 0;
}
