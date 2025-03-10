#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int Elemtype;

typedef struct LNode {
    Elemtype data;
    struct LNode* next;
}LNode, *LinkList;
//or typedef LNode *LinkList;

Status InitList(LinkList* L){
    *L = (LinkList)malloc(sizeof(struct LNode));
    if (!*L)//如果内存分配失败
        exit(OVERFLOW);
    (*L)->next = NULL;
    return OK;
}

void CreateList(LinkList* L, int n){
    //逆位序(结点插在表头)输入n个元素的值，建立带头节点的单链线性表L
    int i;
    LinkList p;
    *L = (LinkList)malloc(sizeof(struct LNode));
    (*L)->next = NULL;
    printf("请输入%d个数据\n", n);
    for(i=n; i>0; --i){
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
    
}

void CreateList1(LinkList* L, int n){
    int i;
    LinkList p, q;
    *L = (LinkList)malloc(sizeof(struct LNode));
    (*L)->next = NULL;
    q = *L;
    printf("请输入%d个数据\n", n);
    for (i=1; i<=n; i++){
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &p->data);
        q->next = p;
        q = q->next;
    }
    p->next = NULL;
    
}

void MergeList(LinkList La, LinkList Lb, LinkList* Lc){
    LinkList pa = La->next, pb = Lb->next, pc;
    *(Lc) = pc = La;//La的头节点被用于Lc的头节点
    while(pa && pb){
        if (pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
       
    }
    pc->next = pa ? pa : pb;//pa为空?如果不为空，插入pa；如果为空，插入pb
        free(Lb);//Lb的头节点未被使用，是多余的，所以可以释放
        Lb = NULL;
}

void DestoryList(LinkList L){
    LinkList q;
    while(L){
        q = L->next;
        free(L);
        L = q;
    }
}

void ClearList(LinkList L){
    LinkList p = L->next;
    L->next = NULL;
    DestoryList(p);
}

Status ListEmpty(LinkList L){
    if (L->next)
        return FALSE;
    else 
        return TRUE;
}

int LinkLength(LinkList L){
    int i = 0;
    LinkList p = L->next;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, Elemtype* e){
    int j  = 1;
    LinkList p = L->next;
    while (p && j < i){
        j++;
        p = p->next;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

int LocateElem(LinkList L, Elemtype e, bool(*compare)(Elemtype, Elemtype)){
    int i = 0;
    LinkList p = L->next;
    while(p){
        i++;
        if (compare(p->data, e))
            return i;
        p = p->next;
    }
    return 0;
}

Status PriorElem(LinkList L, Elemtype cur_e, Elemtype* pre_e){
    LinkList q, p = L->next;
    while(p && p->next){
        q = p->next;
        if (q->data == cur_e){
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return ERROR;
}

Status NextElem(LinkList L, Elemtype cur_e, Elemtype* next_e){
    LinkList p = L->next;
    while (p && p->next){
        if (p->data == cur_e){
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

Status ListInsert(LinkList L, int i, Elemtype e){
    int j = 0;
    LinkList s, p = L;
    while (p && j < i-1){
        j++;
        p = p->next;
    }
    if (!p || j > i - 1)
        return ERROR;
    s = (LinkList)malloc(sizeof(struct LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L, int i, Elemtype* e){
    int j = 0;
    LinkList q, p = L;
    while (p->next && j < i - 1){
        j++;
        p = p->next;
    }
    if (!p->next || j > i - 1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void ListTraverse(LinkList L, void(*visit)(Elemtype)){
    LinkList p = L->next;
    while(p){
        visit (p->data);
        p = p->next;
    }
    printf("\n");
}

void print(Elemtype e){
    printf("%d ", e);
}

bool compare(Elemtype a, Elemtype b){
    return a == b;
}

int main(void){
    LinkList L;
    Elemtype e, e0;
    Status i;
    int j, k;

    /*
    InitList(&L);

    for (j=1; j<=5; j++){
        i = ListInsert(L, 1, j);
    }
    printf("在L的表头依此插入1~5后, L= ");
    ListTraverse(L, print);
    
    i = ListEmpty(L);
    printf("L是否为空? i = %d (1:yes, 0:no), 表L的长度 = %d\n", i, LinkLength(L));

    ClearList(L);
    printf("清空L后, L = ");

    i = ListEmpty(L);
    printf("L是否为空? i = %d(1:yes, 0:no), 表L的长度 = %d\n", i, LinkLength(L));

    for(j=1; j<=10; j++)
        ListInsert(L, j, j);//在L的表尾插入j
    printf("在L的表尾依此插入1~10后, L = ");
    ListTraverse(L, print);

    for (j=0; j<=1; j++){
        k = LocateElem(L, j, compare);
        if(k)
            printf("第%d个元素的值为%d\n,", k, j);
        else
            printf("没有值为%d的元素 ", j);
    }

    for (j=1; j<=2; j++){
        GetElem(L, j, &e0);
        i = PriorElem(L, e0, &e);//求e0的前驱，如成功，将值赋给e
        if(i == ERROR)
            printf("元素%d无前驱,", e0);
        else
            printf("元素%d的前驱为%d\n", e0, e);
    }

    for(j=LinkLength(L)-1; j<=LinkLength(L); j++){
        GetElem(L, j, &e0);
        i = NextElem(L, e0, &e);
        if(i == ERROR)
            printf("元素%d无后继\n", e0);
        else
            printf("元素%d的后继为%d,", e0, e);
    }
    k = LinkLength(L);
    for (j = k + 1; j >= k; j--){
        i = ListDelete(L, j, &e);
        if(i == ERROR)
            printf("删除第%d个元素失败(不存在此元素).", j);
        else
            printf("删除第%d个元素成功,其值为%d\n", j, e);
    }
    printf("依次输出L的元素: ");
    ListTraverse(L, print);
    DestoryList(L);
    printf("销毁L后,L = %u\n", L);
    */

    int n = 5;
    LinkList La, Lb, Lc;
    printf("按非递减顺序,");
    CreateList1(&La, n);//正位序
    printf("La = ");
    ListTraverse(La, print);
    printf("按非递增顺序,");
    CreateList(&Lb, n);//逆位序
    printf("Lb = ");
    ListTraverse(Lb, print);
    MergeList(La, Lb, &Lc);
    printf("Lc = ");
    ListTraverse(Lc, print);

    return 0;
}


