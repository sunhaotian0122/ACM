#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int a,b,c,d,num;
};
node ans[750];

int bfs()
{
    int num=1;
    node x,s,tmp;
    x.a=x.b=x.c=x.d=0,x.num=12;
    queue<node>q;
    q.push(x);
    while(!q.empty())
    {
        s = q.front();q.pop();
        if(s.num==12)
        {
            s.num=10;
            tmp=s;
            tmp.a+=3,q.push(tmp);
            tmp=s;
            tmp.a+=1,tmp.b+=1,q.push(tmp);
            tmp=s;
            tmp.b+=3,q.push(tmp);
            continue;
        }
        if(s.num==10)
        {
            s.num=9;
            tmp=s;
            tmp.a+=3,q.push(tmp);
            tmp=s;
            tmp.a+=1,tmp.c+=1,q.push(tmp);
            tmp=s;
            tmp.c+=3,q.push(tmp);
            continue;
        }
        if(s.num==9)
        {
            s.num=6;
            tmp=s;
            tmp.a+=3,q.push(tmp);
            tmp=s;
            tmp.a+=1,tmp.d+=1,q.push(tmp);
            tmp=s;
            tmp.d+=3,q.push(tmp);
            continue;
        }
        if(s.num==6)
        {
            s.num=5;
            tmp=s;
            tmp.b+=3,q.push(tmp);
            tmp=s;
            tmp.b+=1,tmp.c+=1,q.push(tmp);
            tmp=s;
            tmp.c+=3,q.push(tmp);
            continue;
        }
        if(s.num==5)
        {
            s.num=3;
            tmp=s;
            tmp.b+=3,q.push(tmp);
            tmp=s;
            tmp.b+=1,tmp.d+=1,q.push(tmp);
            tmp=s;
            tmp.d+=3,q.push(tmp);
            continue;
        }
        if(s.num==3)
        {
            tmp=s;
            tmp.c+=3;
            ans[num++]=tmp;
            tmp=s;
            tmp.c+=1,tmp.d+=1;
            ans[num++]=tmp;
            tmp=s;
            tmp.d+=3;
            ans[num++]=tmp;
            continue;
        }
    }
    return num;
}

int main()
{
    int num=bfs();
    int t,a,b,c,d,nn;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        nn=0;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for(int i=1;i<num;i++)
        {
            if(ans[i].a==a&&ans[i].b==b&&ans[i].c==c&&ans[i].d==d) nn++;
        }
        if(nn==1) printf("Case #%d: Yes\n",ca);
        else if(nn>1) printf("Case #%d: No\n",ca);
        else printf("Case #%d: Wrong Scoreboard\n",ca);
    }
    return 0;
}
