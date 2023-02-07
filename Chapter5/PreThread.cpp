//
// Created by Wade1080 on 2023/2/7.
//

/*
 * typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
 */
ThreadNode *pre =NULL;


typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T){
    if(T!=NULL){
        visit(T);//先处理根节点
        if(T->ltag==0)//先处理根节点
            PreThread(T->lchild);//lchild不是前驱线索
        PreThread(T->rchild);
    }
}

void visit(ThreadNode *q){
    if(q->lchild=q){//左子树为空，建立前驱线索
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild=q;//建立前驱结点的后继线索
        pre->rtag=1;
    }
}

void CreatePreThread(ThreadTree T){
    pre=NULL;
    if(T!=NULL){//非空二叉树才能线索化
        PreThread(T);//线序线索化二叉树
        if(pre->rchild==NULL)
            pre->rtag=1;//处理遍历的最后一个结点
    }
}

