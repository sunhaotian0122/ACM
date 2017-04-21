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

long long ans,sz[1000005],tmp[1000005];

void MERGE(int left,int mid,int right)
{
    int i=left,j=mid+1,cnt=0;
    while(i<=mid&&j<=right)
    {
        if(sz[i]<=sz[j])
        {
            tmp[cnt++]=sz[i];
            i++;
        }
        else
        {
            tmp[cnt++]=sz[j];
            j++;
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        tmp[cnt++]=sz[i++];
    }
    while(j<=right)
    {
        tmp[cnt++]=sz[j++];
    }
    cnt=0;
    for(int k=left;k<=right;k++) sz[k]=tmp[cnt++];
}

void merge_sort(int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        MERGE(left,mid,right);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d",&sz[i]);
        ans=0;
        merge_sort(0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
