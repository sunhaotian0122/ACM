#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
map<char,int>mp;
char sz[1005];

int main()
{
    int t,tmp;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%s",sz);
        int ans = INF;
        mp.clear();
        for(int i=0;i<strlen(sz);i++)
        {
            if(!mp[sz[i]]) mp[sz[i]] = i;
            else
            {
                tmp = i-mp[sz[i]];
                if(tmp<ans) ans=tmp;
                mp[sz[i]]=i;
            }
        }
        if(ans==INF) printf("Case #%d: -1\n",ca);
        else printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
