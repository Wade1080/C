#include <malloc.h>
//循环双链表
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化一个循环单链表
bool InitList(LinkList &L){
    L=(LNode *) malloc (sizeof (LNode));
    if(L==NULL)
        return false;
    L->next=L;
    return true;
}

bool Empty(LinkList L){
    if(L->next==L)
        return true;
    else
        return false;
}

//判断节点p是否为循环单链表的表尾节点
bool isTail(LinkList L,LNode *p){
    if(p->next==L)
        return true;
    else
        return false;
}




//循环双链表
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinklist;
bool InitDLinkList(DLinklist &L){
    L=(DNode *) malloc(sizeof (DNode));
    if(L==NULL)
        return false;
    L->next=L;
    L->prior=L;
    return true;
}


void testDLinkList(){
    //初始化循环双链表
    DLinklist L;
    InitDLinkList(L);
}






