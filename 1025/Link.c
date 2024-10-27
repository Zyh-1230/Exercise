#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct {
    int size;
    Node* data;
}MyLinkedList;

MyLinkedList* myLinkedListCreate(void);
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);

int main(void)
{
    MyLinkedList* obj = myLinkedListCreate();

    int val;
    printf("Please enter your wanted number:");
    scanf("%d", &val);
    myLinkedListAddAtHead(obj, val);
    /*
    printf("After adding value %d:\n", val);
    Node* temp = obj->data;
    while (temp != NULL) {
        printf("Value: %d\n", temp->val);
        temp = temp->next;
    }
    */
    
    int val2;
    printf("Please enter your wanted number:");
    scanf("%d", &val2);
    myLinkedListAddAtTail(obj, val2);

    
    /*
    int val3;
    int index0;
    printf("Please enter your wanted number:");
    scanf("%d", &val3);
    printf("Please enter the number of the position you wanted to place it:");
    scanf("%d", &index0);
    myLinkedListAddAtIndex(obj, index0, val3);
    */
    printf("After adding value:\n");
    Node* temp = obj->data;
    while (temp != NULL) {
        printf("Value: %d\n", temp->val);
        temp = temp->next;
    }

    int index1;
    printf("Please enter the place you perferred to delete:");
    scanf("%d", &index1);
    myLinkedListDeleteAtIndex(obj, index1);

    Node* temp2 = obj->data;
    while (temp2 != NULL) {
        printf("Value: %d\n", temp2->val);
        temp2 = temp2->next;
    }

    /*
    int index;
    printf("Please enter the number of the position you wanted to check:");
    scanf("%d", &index);
    int result = myLinkedListGet(obj, index);
    if(result != INT_MIN)
        printf("The value at index %d is %d\n", index, result);
    else
        printf("Index is out of bounds.\n");
    */
    
    myLinkedListFree(obj);

    return 0;
}

MyLinkedList* myLinkedListCreate(void) {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Node* head = (Node*)malloc(sizeof(Node));
    //head->next = NULL;
    obj->data = NULL;//head;        //会导致链表中莫名出现一个数0
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index > obj->size)
        return INT_MIN;             //防止设定-1等值时与用户输入的值冲突
    Node* cur = obj->data;

    while(index > 0 && cur != NULL)
    {
        cur = cur->next;
        index--;
    }
    if(cur == NULL)
        return INT_MIN;

    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = obj->data;
    obj->data = newnode;

    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));//新定义一个节点 默认指向NULL
    Node* cur = obj->data;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    newnode->val = val;
    cur->next = newnode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size)  //index可以等于obj->size 即是尾部
        return;

    Node* newnode = (Node*)malloc(sizeof(Node));
    if(index == 0)
    {   newnode->val = val;
        newnode->next = obj->data;
        obj->data = newnode;
    }  
    else
    {  
        Node* cur = obj->data;
        for(int i=0; i<index-1; ++i)
        {
            cur = cur->next;
        }
        newnode->val = val;
        newnode->next = cur->next;
        cur->next = newnode;
    }
    /*
    while(index > 0)            //需要单独讨论index=0的情况 即在头部插入节点
    {
        cur = cur->next;
        index--;
    }
    newnode->val = val;
    newnode->next = cur->next;
    cur->next = newnode;
    */
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index > obj->size)
        return;
    
    /*
    Node* cur = obj->data;

    while(index > 0)
    {
        cur = cur->next;
        index--;
    }

    cur->next = cur->next->next;
    */
   Node* cur= obj->data;//error Node* cur;
   if(index == 0)
   {
        //error cur = obj->data;  注意不能放在里面 否则else里面的cur没有初始化 变成野指针
        obj->data = cur->next;
        free(cur);
   }
   else
   {
        for(int i=0; i<index-1; ++i)
        {
            cur = cur->next;
        }
        Node* tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
   }
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj == NULL)
        return;  

    Node* tmp = obj->data;
	while (tmp != NULL) {
		Node* n = tmp;
	    tmp = tmp->next;
        free(n);
	}
	free(obj);
}
