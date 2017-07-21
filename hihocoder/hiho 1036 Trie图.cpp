#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;

char word[maxn],str[maxn];

int n;

struct node{
    node *next[26];
    node *fail;
    int num;
    node()
    {
        for(int i=0;i<26;i++) next[i] = NULL;
        fail = NULL;
        num = 0;
    }
}*root;

void init()
{
    root = new node();
}

void ac_insert()
{
    node *p = root;
    for(int i=0;word[i];i++)
    {
        int id = word[i]-'a';
        if(p->next[id]==NULL) p->next[id] = new node;
        p = p->next[id];
    }
    p->num++;
}

void ac_setTrieGraph()
{
    node *p,*tmp;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        p = q.front(),q.pop();
        for(int i=0;i<26;i++)
        {
            if(p->next[i]==NULL)
			{
				if(p==root) p->next[i] = root;
				else p->next[i] = p->fail->next[i];
			}
			else
			{
				if(p==root)
				{
					p->next[i]->fail = root;
					q.push(p->next[i]);
				}
				else
				{
					tmp = p->fail;
					while(tmp)
					{
						if(tmp->next[i])
						{
							p->next[i]->fail = tmp->next[i];
							break;
						}
						tmp = tmp->fail;
					}
					if(tmp==NULL) p->next[i]->fail = root;
					q.push(p->next[i]);
				}
			}
        }
    }
}

bool ac_automation()
{
    node *p = root;
    for(int i=0;str[i];i++)
    {
        int id = str[i]-'a';
        p = p->next[id];
        if(p->num>0) return true;
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    init();
    while(n--)
    {
        scanf("%s",word);
        ac_insert();
    }
    ac_setTrieGraph();
    scanf("%s",str);
    if(ac_automation()) printf("YES\n");
    else printf("NO\n");
    return 0;
}
