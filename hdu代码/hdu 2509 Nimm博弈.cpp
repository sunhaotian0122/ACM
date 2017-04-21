#include <bits/stdc++.h>
using namespace std;
int sz[55];
void init()
{
    sz[0]=0;sz[1]=1;
    for(int i=2;i<55;i++) sz[i]=sz[i-1]+sz[i-2];
}
int main()
{
    int n;
    bool flag;
    init();
    while(~scanf("%d",&n)&&n!=0)
    {
        flag = false;
        for(int i=1;i<55;i++)
        {
            if(n==sz[i])
            {
                printf("Second win\n");
                flag=true;
            }
        }
        if(!flag) printf("First win\n");
    }
    return 0;
}
