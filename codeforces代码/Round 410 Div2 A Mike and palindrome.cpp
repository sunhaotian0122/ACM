#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    if(str.length()&1)
    {
        int tmp = 0;
        for(int i=0;i<(str.length()-1)/2;i++)
        {
            if(str[i]==str[str.length()-1-i]) continue;
            else tmp++;
        }
        if(tmp<=1) printf("YES\n");
        else printf("NO\n");
    }
    else
    {
        int tmp=0;
        for(int i=0;i<str.length()/2;i++)
        {
            if(str[i]==str[str.length()-i-1]) continue;
            else tmp++;
        }
        if(tmp==1) printf("YES\n");
        else printf("NO\n");
    }
}
