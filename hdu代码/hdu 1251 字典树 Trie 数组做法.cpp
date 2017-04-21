#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int trie[maxn][26],num[maxn],cnt=1;

void Trie_insert(char word[])
{
    int n=0;
    for(int i=0;word[i];i++)
    {
        if(trie[n][word[i]-'a']==0) trie[n][word[i]-'a']=cnt++;
        n = trie[n][word[i]-'a'];
        num[n]++;
    }
}

int Trie_search(char word[])
{
    int n=0;
    for(int i=0;word[i];i++)
    {
        if(trie[n][word[i]-'a']==0) return 0;
        n = trie[n][word[i]-'a'];
    }
    return num[n];
}

int main()
{
    char word[11];
    while(gets(word))
    {
        if(word[0]==NULL) break;
        Trie_insert(word);
    }
    while(scanf("%s",word)!=EOF)
    {
        printf("%d\n",Trie_search(word));
    }
    return 0;
}
