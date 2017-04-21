#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

map<string,int>mp;
const int INF = 0x3f3f3f3f;
char sz[200][50];
int dist[200][200];

int main()
{
    int n,t,num;
    char s[50],e[50];
    while(~scanf("%d",&n)&&(n!=-1))
    {
        bool flag=false;
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                if(i==j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }
        t=1;
        mp.clear();
        scanf("%s%s",s,e);
        if(strcmp(s,e)==0)
        {
            flag=true;
        }
        mp[s]=t++;
        mp[e]=t++;
        for(int i=1;i<=n;i++)
        {
            scanf("%s%s",s,e);
            scanf("%d",&num);
            if(!mp[s]) mp[s] = t++;
            if(!mp[e]) mp[e] = t++;
            dist[mp[s]][mp[e]] = dist[mp[e]][mp[s]] = num;
        }
        for(int k=1;k<t;k++)
        {
            for(int i=1;i<t;i++)
            {
                for(int j=1;j<t;j++)
                {
                    dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        if(dist[1][2]==INF) printf("-1\n");
        else printf("%d\n",dist[1][2]);
    }
    return 0;
}
