#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Trie{
    Trie *next[26];
    int num;
    Trie()
    {
        for(int i=0;i<26;i++) next[i]=NULL;
        num=0;
    }
}root;

int idx(char s)
{
    return s-'a';
}

void Trie_insert(char word[])
{
    Trie *p=&root;
    for(int i=0;word[i];i++)
    {
        if(p->next[idx(word[i])]==NULL) p->next[idx(word[i])] = new Trie;
        p = p->next[idx(word[i])];
        p->num++;
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
    char word[11];
    while(cin.getline(word,11))
    {
        if(strlen(word)==0) break;
        Trie_insert(word);
    }
    while(scanf("%s",word)!=EOF)
    {
        printf("%d\n",Trie_search(word));
    }
    return 0;
}
