//
// Created by Wade1080 on 2023/2/9.
//
//二叉排序树结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//在二叉排序树中查找值为key的结点
/*
 * 若树非空，目标值与根结点的值比较：
 * 若相等，则查找成功;
 * 若小于根结点，则在左子树上找，否则在右子树上查找
 * 查找成功，返回结点指针；查找失败返回NULL
 */



//非递归实现方式——效率好（空间复杂度低）
BSTNode *BST_Search(BSTree T,int key){
    while (T!=NULL&&key!=T->key){//若树空或等于根结点值，则结束循环
        if(key<T->key)//小于，则在左子树上查找
            T=T->lchild;
        else
            T=T->rchild;//大于，则在右子树上查找
    }
    return T;
}



//递归实现方式
BSTNode *BSTSearch(BSTree T,int key){
    if(T==NULL){
        return NULL;//查找失败
    }
    if(key==T->key){
        return T;
    }
    else if(key < T->key){
        return BSTSearch(T->lchild,key);//在左子树中找
    }
    else {
        return BSTSearch(T->rchild,key);//在右子树中查找
    }
}

//在二叉排序树插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree &T,int k){
    if(T==NULL){//原树为空，新插入的结点为根结点
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key){
        return 0;//树中存在相同关键字的结点，插入失败
    }
    else if(k<T->key){
        return BST_Insert(T->lchild,k);//插入到T的左子树
    }
    else{
        return BST_Insert(T->rchild,k);//插入到T的右子树

    }
}

/*
 * 错误实例，在循环中跟新k而不是更新T，其次没有考虑结点未空的情况，应该在插入结点之前检查结点是否为空，如果为空则直接创建结点
 */
int BSTInsert(BSTree &T,int k){
    while(T!=NULL&&k!=T->key){
        if(k<T->key){
            T=T->lchild;
        } else if(k>T->key){
            T=T->rchild
        }
    }
    T=(BSTNode)malloc(sizeof(BSTNode));
    T->key=k;
    T->rchild=T->rchild=NULL;
    return 1;
}


int BSTInsert(BSTNode &T,int k){
    if(T==NULL){
        T=(BSTNode)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T.rchild=NULL;
        return 1;
    } else{
        if(k<T->key){

        }
    }
}


