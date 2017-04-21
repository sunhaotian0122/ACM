#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

vector<int>pile[25];
int n;

void find_num(int a,int &p,int &h)
{
    for(p=0;p<n;p++)
    {
        for(h=0;h<pile[p].size();h++)
        {
            if(pile[p][h]==a) return;
        }
    }
}

void clear_above(int p,int h)
{
    for(int i=h+1;i<pile[p].size();i++)
    {
        int x=pile[p][i];
        pile[x].push_back(x);
    }
    pile[p].resize(h+1);
}

void pile_onto(int p,int h,int p2)
{
    for(int i=h;i<pile[p].size();i++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print()
{
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++) printf(" %d",pile[i][j]);
        printf("\n");
    }
}

int main()
{
    int a,b;
    char s1[10],s2[10];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) pile[i].push_back(i);
        while(scanf("%s",s1)&&s1[0]!='q')
        {
            scanf("%d%s%d",&a,s2,&b);
            int pa,pb,ha,hb;
            find_num(a,pa,ha);
            find_num(b,pb,hb);
            if(pa==pb) continue;
            if(s2[1]=='n') clear_above(pb,hb);
            if(s1[0]=='m') clear_above(pa,ha);
            pile_onto(pa,ha,pb);
        }
        print();
    }
    return 0;
}
