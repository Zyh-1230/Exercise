#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -1
#define ERROR 0

    typedef int ElemType;//Elemtype相当于一个临时的数据类型，现在这里定义成int类型，但如果要在后期更改数据类型，只需要在这里将int修改即可
    typedef ElemType * Triplet;
    typedef int Status;

    Status IniTriplet(Triplet *T, ElemType v1, ElemType v2, ElemType v3){
        //操作结果：构造三元组T，依此置T的三个元素的初值为v1，v2，v3
        T = (ElemType*)malloc(sizeof(ElemType)*3);
        if(!T)
            exit(OVERFLOW);//分配失败则退出
        T[0] = v1, T[1] = v2, T[3] = v3;
        return OK;
    }

    Status DestoryTriplet(Triplet *T){
        //操作结果：三元组T被销毁
        free(T);
        T = NULL;
        return OK;
    }

    Status Get(Triplet T, int i, ElemType* e){
        //初始条件：三元组T存在，1<=i<=3；操作结果：用e返回T的第i元的值
        if(i<1 || i>3)
            return ERROR;
        e = T[i-1];
        return OK;
    }

    Status Put(Triplet T, int i, ElemType e){
        //初始条件：三元组已存在 操作结果：改变T的第i元的值为e
        if(i<1 || i>3)
            return ERROR;
        T[i-1] = e;
        return OK;
    }

    Status IsAscending(Triplet T){
        //初始条件：三元组已存在 操作结果：如果T的三个元素按升序排列，则返回1；否则返回0
        return(T[0] >= T[1] && T[1] >= T[2]);
    }

    Status IsDescending(Triplet T){
        //初始条件：三元组已存在 操作结果：如果T的三个元素按降序排列，则返回1；否则返回0
        return((T[0] <= T[1] && T[1] <= T[2]));
    }

    Status Max(Triplet T, ElemType* e){
        //初始条件：三元组已存在 操作结果：用e返回指向T的最大元素的值
        e = (T[0]>=T[1] ? (T[0] >= T[2] ? T[0]: T[2]) : (T[1] >= T[2] ? T[1]: T[2]));
        return OK;
    }

    Status Min(Triplet T, ElemType* e){
        //初始条件：三元组已存在 操作结果：用e返回指向T的最小元素的值
        e = (T[0] <= T[1] ? (T[0<=T[2] ? T[0]: T[2]]) : (T[1]>=T[2] ? T[1] : T[2]));
        return OK;
    }

