#include <cstdio>
using namespace std;

const int maxm=1e4+5,maxn=1e6+5;
int n,m,sn[maxn],sm[maxm],next[maxm];

void set_next()
{
    next[0]=next[1]=0;
    for(int i=1;i<m;i++)
    {
        int tmp=next[i];
        while(tmp && sm[i]!=sm[tmp]) tmp = next[tmp];
        if(sm[i]==sm[tmp]) tmp++;
        next[i+1]=tmp;
    }
}

int main()
{
    int t,num;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&sn[i]);
        for(int i=0;i<m;i++) scanf("%d",&sm[i]);
        set_next();
        flag=false;
        num=0;
        for(int i=0;i<n;i++)
        {
            while(num && sn[i]!=sm[num]) num=next[num];
            if(sn[i]==sm[num]) num++;
            if(num==m)
            {
                flag=true;
                printf("%d\n",i-m+2);
                break;
            }
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}
