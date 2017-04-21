#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

void mmax(int *a,int *b,int *c)
{
    int x;
    if(*a<*b)
    {
        x = *a;
        *a = *b;
        *b = x;
    }
    if(*a<*c)
    {
        x = *a;
        *a = *c;
        *c = x;
    }
    if(*b<*c)
    {
        x = *b;
        *b = *c;
        *c = x;
    }
}

map<string,int>mp;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        int n,v[105],next[105],ans,x1,x2;
        scanf("%d",&n);
        memset(next,-1,sizeof(next));
        string str[105];
        for(int i=1;i<=n;i++)
        {
            cin>>str[i]>>v[i];
            if(mp[str[i]])
            {
                next[i] = mp[str[i]];
                mp[str[i]]=i;
            }
            else
            {
                mp[str[i]] = i;
                next[i]=i;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            int tmp = mp[str[i]],num;
            x1=x2=0;
            for(int cas=1;next[tmp]!=-1;cas++)
            {
                if(cas==1)
                {
                    x1 = v[tmp];
                    num = tmp;
                    tmp = next[tmp];
                    next[num]=-1;
                    continue;
                }
                if(cas==2)
                {
                    x2 = v[tmp];
                    num = tmp;
                    tmp = next[tmp];
                    next[num] = -1;
                    continue;
                }
                int cmp = v[tmp];
                num = tmp;
                tmp = next[tmp];
                next[num] = -1;
                mmax(&x1,&x2,&cmp);
            }
            ans += (x1+x2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
