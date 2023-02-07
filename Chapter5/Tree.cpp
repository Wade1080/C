//
// Created by Wade1080 on 2023/2/6.
//
#include <cstdlib>
struct Elemtype{
    int value;
};
typedef struct BITNode{
    Elemtype data;
    struct BITNode *lchild,*rchild;
}BiTNode,*BiTree;

//定义一棵空树
BiTree root = NULL;

//插入根节点
root = (BiTree)malloc(sizeof(BiTNode));//申请一片空间进行存储
root->data={1};
root->lchild=NULL;
root->rchild=NULL;

//插入新结点
BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
p->data={2};
p->lchild=NULL;
p->rchild=NULL;
root->lchild=p;//作为根节点的左孩子


//插入新结点
BiTNode *p1 = (BiTNode *)malloc(sizeof(BITNode));
p1->data={3};
p1->lchild=NULL;
p1->rchild=NULL;
root->rchild=p1;//作为根节点的右孩子