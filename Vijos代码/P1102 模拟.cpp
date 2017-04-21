#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int sz[15],x,ans;
    for(int i=1;i<=10;i++) scanf("%d",&sz[i]);
    scanf("%d",&x);
    x += 30;
    ans=0;
    for(int i=1;i<=10;i++) if(x>=sz[i]) ans++;
    printf("%d\n",ans);
    return 0;
}
