#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int ElemType;

typedef struct{
    ElemType* data;//动态分配的数组
    int length;
    int capacity;//当前分配的最大容量
}List;

void InitList(List* L, int initialCapacity){
    L->data = (ElemType*)malloc(initialCapacity * sizeof(ElemType));
    /*
    feature:
    1.分配的内存是未初始化的，内容不确定
    分配的内存需要手动释放(使用free)*/
    if (!L->data){
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    L->length = 0;
    L->capacity = initialCapacity;
}

void DestoryList(List* L){
    free(L->data);
    L->data = NULL;
    L->length = 0;
    L->capacity = 0;
}

void ClearList(List* L){
    L->length = 0;
}

bool ListEmpty(List L){
    return L.length = 0;
}

int ListLength(List L){
    return L.length;
}

int GetElem(List L, int i, ElemType* e){
    if (i < 1 || i > L.length)
        return 0;
    *e = L.data[i - 1];
    return 1;
}

int LocateElem(List L, ElemType e, bool (*compare)(ElemType, ElemType)){//函数指针：返回类型(*指针名称)(参数列表)
    for (int i = 0; i < L.length; i++){
        if (compare(L.data[i], e))
            return i+1;
    }
    return 0;
}

int PriorElem(List L, ElemType cur_e, ElemType* pre_e){
    for (int i = 1; i < L.length; i++){
        if (L.data[i] == cur_e){
            *pre_e = L.data[i - 1];
            return 1;
        }
    }
    return 0;
}

int NextElem(List L, ElemType cur_e, ElemType* next_e){
    for (int i = 0; i < L.length - 1; i++){
        if (L.data[i] == cur_e){
            *next_e = L.data[i+1];
            return 1;
        }
    }
    return 0;
}

void ExpandList(List* L){
    int newCapacity = L->capacity * 2;
    ElemType* newData = (ElemType*)realloc(L->data, newCapacity * sizeof(ElemType));
    /*
    realloc:重新分配一块已经分配的内存区域，可以扩大/缩小内存块的大小；
    用法(同malloc):(强制转化类型)realloc(指向已分配内存的指针, 新的内存大小)
    feature:
    1.如果新的大小大于原来的大小，realloc会尝试扩展内存块。如果扩展成功，原有数据会被保留，新增部分内容不确定
    2.如果新的大小小于原来的大小，realloc会缩小内存块，多余部分的数据会丢失
    3.如果realloc无法在原地扩展内存块，它会分配一块你的内存区域，并将原有数据复制到新区域，然后释放旧的内存块
    4.如果realloc失败，原始内存块不会被释放，需要手动处理
    
    matters need attention:
    1.原始指针未NULL，realloc的行为等同于malloc
    2.如果新的大小为0，realloc的行为等同于free，并返回NULL
    3.如果realloc失败，原始内存块不会被释放。因此在调用realloc时，应该使用一个临时指针来接收返回值，以免内存泄漏
    正确示例如下：*/
    if (!newData){
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    L->data = newData;
    L->capacity = newCapacity;
}

int ListInsert(List* L, int i, ElemType e){
    if (i < 1 || i > L->length + 1)
        return 0;
    if (L->length >= L->capacity){
        ExpandList(L);
    }
    //当L->length != 0时执行
    for (int j = L->length; j >= i; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return 1;
}

int ListDelete(List* L, int i, ElemType* e){
    if (i < 1 || i > L->length)
        return 0;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 1;
}

void ListTraverse(List L, void (*visit)(ElemType)){
    for (int i = 0; i < L.length; i++){
        visit(L.data[i]);
    }
}

void printElement(ElemType e){
    printf("%d ", e);
}

bool equal(ElemType a, ElemType b){
    return a == b;
}

//O(ListLength(La) * ListLength(Lb))
void Union(List* La, List Lb){
    //将所有在线性表La中但不在Lb中的数据元素插入到表La中
    ElemType e;
    int La_len, Lb_len;
    int i;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++){
        GetElem(Lb, i, &e);
        if(!LocateElem(*La, e, equal))
            ListInsert(La, ++La_len, e);
    }
}

//O(ListLength(La) + ListLength(Lb))
void MergeList(List La, List Lb, List* Lc){
    //已知：La和Lb中的数据元素按值非递减排列
    //归并La和Lb得到新的线性表Lc，Lc的数据元素按值非递减排列（不改变表La和表Lb）
    int i = 1, j = 1, k = 0;
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    ElemType ai, bj;

    InitList(Lc, La_len + Lb_len);
    
    while (i <= La_len && j <= Lb_len){
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        if (ai <= bj){
            ListInsert(Lc, ++k, ai);//++k前自增，在传入ListInsert前k=0+1=1
            i++;
        }
        else{
            ListInsert(Lc, ++k, bj);
            j++;
        }

    }

    //两个while实际只执行一个循环体
    while(i <= La_len){
        GetElem(La, i++, ai);//i++后自增，在得到ai后i=i+1
        ListInsert(Lc, ++k, ai);
    }
    while(j <= Lb_len){
        GetElem(Lb, j++, bj);
        ListInsert(Lc, ++k, bj);
    }
}

int main(){
    List La, Lb;
    InitList(&La, 10);
    InitList(&Lb, 10);

    ListInsert(&La, 1, 10);
    ListInsert(&La, 2, 20);
    ListInsert(&La, 3, 30);

    ListInsert(&Lb, 1, 20);
    ListInsert(&Lb, 2, 40);
    ListInsert(&La, 3, 50);

    printf("La before union: ");
    ListTraverse(La, printElement);
    printf("\n");

    printf("Lb before union: ");
    ListTraverse(Lb, printElement);
    printf("\n");

    Union(&La, Lb);
    
    printf("La after union: ");
    ListTraverse(La, printElement);
    printf("\n");

    MergeList(La, Lb, &Lc);

    printf("Lc after merge: ");
    ListTraverse(Lc, printElement);
    printf("\n");

    DestoryList(&La);
    DestoryList(&Lb);
    DestoryList(&Lc);

    return 0;
}