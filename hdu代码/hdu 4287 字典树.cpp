#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int,int>ans;
map<char,int>id;
int sz[5005];
/*struct Trie{
    Trie *next[26];
    int num;
    Trie()
    {
        for(int i=0;i<26;i++) next[i]=NULL;
        num=0;
    }
}root;

int Trie_search(char word[])
{
    for()
}*/
int main()
{
    int t,n,m,num;
    char word[10];
    id['a']=id['b']=id['c']=2;
    id['d']=id['e']=id['f']=3;
    id['g']=id['h']=id['i']=4;
    id['j']=id['k']=id['l']=5;
    id['m']=id['n']=id['o']=6;
    id['p']=id['q']=id['r']=id['s']=7;
    id['t']=id['u']=id['v']=8;
    id['w']=id['x']=id['y']=id['z']=9;
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&sz[i]);
            ans[sz[i]]=0;
        }
        getchar();
        for(int i=1;i<=m;i++)
        {
            num=0;
            gets(word);
            for(int i=0;i<strlen(word);i++)
            {
                num = num*10+id[word[i]];
            }
            ans[num]++;
        }
        for(int i=0;i<n;i++)
        {
            printf("%d\n",ans[sz[i]]);
        }
    }
    return 0;
}
