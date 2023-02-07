#include <cstdlib>

typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next
}DNode,*DLinklist;

//初始化双链表
bool InitDLinklist(DLinklist &L){
    L=(DNode *)malloc(sizeof (DNode));//分配一个头节点
    if(L==NULL)
        return false;
    L->prior=NULL;//头节点的prior永远指向NULL
    L->next=NULL;//头结点之后暂时还没有节点
    return true;
}


//判断双链表是否为空（带头结点）
bool Empty(DLinklist L){
    if(L->next==NULL)
        return true;
    else
        return false;
}

/*
//双链表的插入
bool InsertNextDNode(DNode *p,DNode *s){
    s->next=p->next;//将节点*s插入到节点*p之后
    p->next->prior=s;
    s->prior=p;
    p->next=s;
}*/



//双链表的插入（改进）
bool InsertNextDNode(DNode *p,DNode *s){
    if(p==NULL || s==NULL)//非法参数
        return false;
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
    s->prior=p;
    return true;
}

//删除p节点的后继节点
bool DeleteNextDNode(DNode *p){
    if(p==NULL)
        return false;
    DNode *q = p->next;//找到p的后继节点q
    if(q==NULL)
        return false; //p没有后继节点
    if(q->next!=NULL)//q节点不是最后一个节点
        q->next->prior=p;
    free(q);//释放节点空间
    return true;
}
//双链表的遍历
while(p!=NULL){
    p=p->next;
}



void testDLinklist(){
    //初始化双链表
    DLinklist L;
    InitDLinklist(L);
}