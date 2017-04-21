#include<bits/stdc++.h>
using namespace std;
int n;
int a[25];
int main()
{
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 1;
    a[5] = 1;
    a[6] = 2;
    a[7] = 3;
    a[8] = 3;
    a[9] = 4;
    a[10] = 5;
    a[11] = 6;
    a[12] = 7;
    a[13] = 7;
    a[14] = 8;
    a[15] = 9;
    a[16] = 10;
    a[17] = 11;
    a[18] = 12;
    a[19] = 13;
    a[20] = 14;
    int T;
    scanf("%d",&T);
    int Case = 1;
    while(T--)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",Case++,a[n]);
    }
    return 0;
}
