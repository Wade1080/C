#include <iostream>
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;//队列的队头和队尾指针
}LinkQueue;

//初始化队列(带头结点)
void InitQueue(LinkQueue &Q){
    //初始时 front\rear 都指向头节点
    Q.front = Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

//初始化队列（不带头节点
/*void InitQueue(LinkQueue &Q){
    Q.front=NULL;
    Q.rear=NULL;
}*/

bool IsEmpty(LinkQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
}


void testLinkQueue(){
    LinkQueue Q;//声明一个队列
    InitQueue(Q);//初始化队列
}

//新元素入队(带头节点)
void EnQueue (LinkQueue &Q,ElemType x){
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s; //新结点插入到rear之后
    Q.rear=s;//修改表尾指针
}
//新元素入队（不带头结点）
void EnQueue(LinkQueue &Q,Elemtype x){
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;//都是在队尾，永远指向null
    if(Q.front==NULL){
        Q.front=s;//在空队列中插入第一个元素
        Q.rear=s;//修改队头队尾指针
    }else{
        Q.rear->next=s;//新结点插入到 rear 结点之后
        Q.rear=s;//修改rear指针
    }
}

//队头元素出队(带头结点)
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front==Q.rear)//空队
        return false;
    LinkNode *p=Q.front->next;//队头元素指针
    x=p->data;//用变量x返回队头元素
    Q.front->next=p->next;//修改头结点的next指针
    if(Q.rear==p)//此时是最后一个结点出队
        Q.rear=Q.front;//修改rear指针
    free(p);//释放结点空间
    return true;
}

//队头元素出队（不带头结点）
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front==NULL)//空队
        return false;
    LinkNode *p=Q.front;//p指向此次出队的结点
    x=p->data;//用变量x返回队头元素
    Q.front=p->next;//修改 front 指针
    if(Q.rear==p){//此次是最后一个结点出队
        Q.front=NULL;//front 指向NULL
        Q.rear=NULL;//rear 指向NULL
    }
    free(p);//释放结点空间
    return true;
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
