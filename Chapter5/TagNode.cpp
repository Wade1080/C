//
// Created by Wade1080 on 2023/2/6.
//
//二叉树的结点（链式存储）

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//线索二叉树结点
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
//tag==0,表示指针指向孩子；tag==1,表示指针是”线索“


void Inthread(ThreadTree T){
    if(T!=NULL){
        //中序遍历
        Inthread(T->lchild);
        visit(T);
        Inthread(T->rchild)
    }
}

void visit(ThreadNode *q){
    if(q->lchild==NULL){//左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;//建立前驱结点的后继线索
        pre->rtag=1;
    }
    pre=q;
}
//全局变量 pre，指向当前访问结点的前驱
ThreadNode *pre=NULL;
//最后还要检查pre的rchild是否为NULL，如果是，则令rtag=1