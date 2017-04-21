#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
    int value;
    char ch;
}Node[10];
bool cmp(node n1,node n2)
{
    if(n1.value == n2.value) return n1.ch < n2.ch;
    else return n1.value > n2.value;
}
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0&&m == 0) break;
        char x;
        Node[1].value = 0;
        Node[1].ch = 'A';
        Node[2].value = 0;
        Node[2].ch = 'C';
        Node[3].value = 0;
        Node[3].ch = 'D';
        Node[4].value = 0;
        Node[4].ch = 'E';
        Node[5].value = 0;
        Node[5].ch = 'G';
        getchar();
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%c",&x);
                for(int k = 1; k <= 5; k++)
                {
                    if(x == Node[k].ch)
                    {
                        Node[k].value++;
                        break;
                    }
                }
            }
            getchar();
        }
        sort(Node + 1,Node + 6,cmp);
        bool flag = true;
        for(int i = 1; i <= 5; i++)
        {
            if(Node[i].value != 0)
            {
                if(flag)
                {
                    printf("%c %d",Node[i].ch,Node[i].value);
                    flag = false;
                }
                else printf(" %c %d",Node[i].ch,Node[i].value);
            }
        }
        printf("\n");
    }
    return 0;
}
