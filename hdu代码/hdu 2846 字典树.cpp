#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;

struct Trie{
    Trie *next[26];
    int num;
    int id;
    Trie()
    {
        for(int i=0;i<26;i++) next[i]=NULL;
        num=0;
        id=0;
    }
}root;

int idx(char s)
{
    return s-'a';
}

void Trie_insert(char word[],int x)
{
    Trie *p=&root;
    for(int i=0;word[i];i++)
    {
        if(p->next[idx(word[i])]==NULL) p->next[idx(word[i])]=new Trie;
        p = p->next[idx(word[i])];
        if(p->id!=x)
        {
            p->id=x;
            p->num++;
        }
    }
}

int Trie_search(char word[])
{
    Trie *p=&root;
    for(int i=0;word[i];i++)
    {
        if(p->next[idx(word[i])]==NULL) return 0;
        p = p->next[idx(word[i])];
    }
    return p->num;
}

int main()
{
    char word[25];
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        gets(word);
        for(int j=0;j<strlen(word);j++)
        {
            Trie_insert(word+j,i);
        }
    }
    scanf("%d",&m);
    getchar();
    for(int i=1;i<=m;i++)
    {
        gets(word);
        printf("%d\n",Trie_search(word));
    }
    return 0;
}
