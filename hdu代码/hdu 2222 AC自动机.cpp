#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;

int t,n;

char word[55],str[maxn];

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
};

node *root;

void init()
{
    root = new node;
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

void ac_setFail()
{
    node *p,*tmp;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        p = q.front(),q.pop();
        for(int i=0;i<26;i++)
        {
            if(p->next[i]==NULL) continue;
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

int ac_automation()
{
    int ans=0;
    node *p = root;
    node *tmp;
    for(int i=0;str[i];i++)
    {
        int id = str[i]-'a';
        while(p->next[id]==NULL && p!=root) p = p->fail;
        if(p->next[id]!=NULL) p = p->next[id];
        tmp = p;
        while(tmp!=root)
        {
            if(tmp->num>0)
            {
                ans += tmp->num;
                tmp->num = 0;
            }
            else tmp = tmp->fail;
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",word);
            ac_insert();
        }
        ac_setFail();
        scanf("%s",str);
        printf("%d\n",ac_automation());
    }
    return 0;
}
