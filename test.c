#include <malloc.h>
#include <stdio.h>

struct LNode //
{
    int num, pd; //num用来储存序号，pd为密码
    struct LNode* next;
};
struct LNode *head, *p, *pt;
int Initlink(int n)
{
    int i;
    head = (struct LNode*)malloc(sizeof(struct LNode));
    if (!head)
        return 0;
    p = head;
    for (i = 1; i <= n; i++) {
        pt = (struct LNode*)malloc(sizeof(struct LNode));
        if (!pt)
            return 0;
        p->next = pt;
        p = pt;
    }
    p->next = head;
    return 0;
}
int enterpd(int n) //
{
    int i, j;
    printf(" 请输入密码:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &j);
        pt->num = i; //
        pt->pd = j; //
        pt = pt->next;
    }
    pt = p;
    return 0;
}

int outlist(int m, int n)
{
    int i, a;
    for (i = 1; i <= n; i++) //
    {
        for (a = 1; a < m; a++) {
            pt = pt->next;
        }
        pt = pt->next;
        m = p->pd;
        printf("%d\n", p->num); //
        pt->next = p->next;
        free(p);
    }
    return 0;
}
int main()
{
    int m = 0, n = 0; //
    printf("参数m报数上限,n人数\n");
    printf(" 请输入参数m,n\n");
    scanf("%d%d", &m, &n);
    Initlink(n);
    enterpd(n);
    printf("出队的人依次是：\n");
    outlist(m, n); //
    return 0;
}