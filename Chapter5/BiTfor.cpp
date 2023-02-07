//
// Created by Wade1080 on 2023/2/6.
//
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTNode visit(BiTree T){
    return T->data;
}
//先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);//访问根节点
        PreOrder(T->lchild);//递归遍历左子树
        PreOrder(T->rchild);//递归遍历右子树
    }
}
//中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild)
    }
}



//后序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild)
        visit(T);

    }
}


int treeDepth(BiTree T){
    if(T == NULL){
        return 0;
    } else{
        int l = treeDepth(T->lchild);
        int t = treeDepth(T->rchild);
        //树的深度=MAX(左子树深度,右子树深度)+1
        return l>r?l+1:r+1;
    }
}
//链式队列结点
typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;

typedef  struct {
    LinkNode *front,*rear;
}LinkQueue;


//层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;//初始化辅助队列
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);//将根节点入队
    while(!=IsEmpty(Q)){
        DeQueue(Q,p);//队头结点出队
        visit(p);//访问出队结点
        if(p->lchild!=NUll){
            EnQueue(Q,p->lchild);//左孩子入队
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);//右孩子入队
        }
    }
}
