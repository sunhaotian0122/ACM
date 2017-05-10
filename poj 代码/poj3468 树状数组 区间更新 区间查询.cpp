//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
const int maxn = 1e5+5;
ll a[maxn],c1[maxn],c2[maxn],n,q;

ll lowbit(ll x)
{
    return x&(-x);
}

void update(ll x,ll value)
{
    ll i=x;
    while(x<=n)
    {
        c1[x] += value;
        c2[x] += i*value;
        //����c1[]��ͬʱ����c2[]
        x += lowbit(x);
    }
}

ll query(ll x)
{
    ll tmp1=0,tmp2=0,i=x;
    while(x>0)
    {
        tmp1 += c1[x];
        tmp2 += c2[x];
        x -= lowbit(x);
    }
    return (i+1)*tmp1-tmp2;
    //tmp1 = c1[1]+...+c1[n],tmp2 = c2[1]+...+c2[n] = 1*c1[1]+...+n*c1[n]
    //����a[1]+...+a[x]
}

int main()
{
    ll tmp;
    scanf("%d%d",&n,&q);
    memset(a,0,sizeof(a));
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        //��ʼc1[]��c2[],�������
        update(i,a[i]-a[i-1]);
    }
    int a,b;
    char op;
    while(q--)
    {
        getchar();
        scanf("%c%d%d",&op,&a,&b);
        if(op=='C')
        {
            scanf("%lld",&tmp);
            //�������a[],ͨ�����ε������c1[]ʵ��,����c1[]��ͬʱ����c2[]
            update(a,tmp);
            update(b+1,-tmp);
        }
        else
        {
            printf("%lld\n",query(b)-query(a-1));
            //���a[a]+...+a[b]
        }
    }
    return 0;
}
