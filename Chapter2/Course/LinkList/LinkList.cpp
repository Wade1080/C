//
// Created by Wade1080 on 2023/1/7.
//
typedef struct LNode{// 定义单链表结点类型
    ElemType data;//每个结点存放一个数据元素
    struct LNode *next;//指针指向下一个结点
}LNode,*LinkList;

//初始化一个单链表(带头结点)
bool InitList(LinkList &L){
    L = (LNode *) malloc (sizeof (LNode));//分配一个头结点
    if(L==NULL)
        return false;
    L->next = NULL;//头结点之后暂时还没有结点
    return true;
}


//在第 i 个位置插入元素e(带头结点)
bool ListInsert(LinkList &L,int i ,ElemType e){
    if(i<1)
        return false;
    LNode *p;//指针p指向当前扫描到的结点
    int j=0;//当前p指向的是第几个结点
    p=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(p!=NULL && j<i-1){//循环找到第i-1个结点
        p=p->next;
        j++;
    }
    if(p==NULL)//i值不合法
        return false;
    LNode *s=(LNode *)malloc(sizeof (LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;//将结点s接到p之后
    return true;//插入成功

}



//头插操作
LinkList List_HeadInsert(LinkList &L){ //你想建立单链表
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof (LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
}





//后插操作:在p结点之后插入元素e
bool InsertNextNode(LNode *p,ElemType e){
    if(p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof (LNode));
    if(s==NULL)//内存分配失败
        return false;
    s->data=e;//用结点s保存数据元素e
    s->next=p->next;
    p->next=s;//将结点s连到p之后
    return true;
}

void test(){
    LinkList L;//声明一个指向单链表的指针
    //初始化一个空表
    InitList(L);
};