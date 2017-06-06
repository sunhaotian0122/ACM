#include <bits/stdc++.h>
using namespace std;
#define time_ (printf("%.6f\n", double(clock())/CLOCKS_PER_SEC))
typedef long long ll;
const int INF =  0x3f3f3f3f;
const int maxn = 1e6+5;

char s[maxn],t[maxn];
int n,a,b,l,r,w[maxn],ans,len;
int next[maxn];

void set_next()
{
    next[0]=next[1]=0;
    for(int i=1;i<len;i++)
    {
        int tmp=next[i];
        while(tmp && t[i]!=t[tmp]) tmp = next[tmp];
        if(t[i]==t[tmp]) tmp++;
        next[i+1]=tmp;
    }
}

void kmp()
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        while(num && s[i]!=t[num]) num=next[num];
        if(s[i]==t[num]) num++;
        if(num==len)
        {
            ans++;
            num=next[num];
        }
    }
}

int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&l,&r);
    scanf("%s",t);
    len=strlen(t);
    w[0]=b;
    for(int i=0;i<n;i++)
    {
        if(i>0) w[i] = (w[i-1]+a)%n;
        if(w[i]>=l && w[i]<=r)
        {
            if(w[i]&1) s[i]='T';
            else s[i]='A';
        }
        else
        {
            if(w[i]&1) s[i]='C';
            else s[i]='G';
        }
    }
    s[n]='\0';
    set_next();
    ans=0;
    kmp();
    printf("%d\n",ans);
    return 0;
}
