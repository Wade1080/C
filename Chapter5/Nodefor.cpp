//
// Created by Wade1080 on 2023/2/7.
//
//找到以P为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p){
    //循环找打最左下结点（不一是叶子结点）
    while(p->ltag==0){
        p=p->lchild;
    }
    return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode *Nextnode(ThreadNode *p){
    //右子树中最左下结点
    if(p->rtag==0){
        return Firstnode(p->rchild);//rtag==1没有右孩子，即有中序后继，rtag==0有右孩子，即没有中序后继
    } else{
        return  p->rchild;//rtag==1直接返回后继线索
    }
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(ThreadNode *T){
    // 初始化值，判断条件，循环结束执行
    for(ThreadNode *p= Firstnode(T);p!=NULL;p= Nextnode(p))
        visit(p);
}



//分割线===================

//中序线索二叉树找中序前驱
//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p){
    //循环找到最右下结点（不一定是叶节点）
    while(p->rtag==0){
        p=p->rchild;
    }
    return p;
}
//在中序线索二叉树中找到结点p的前驱结点
ThreadNode *Prenode(ThreadNode *p){
    //左子树中最右下结点
    if(p->ltag==0){
        return Lastnode(p->lchild);
    } else{
        return p->lchild;//ltag==1直接返回前驱线索
    }
}
//对中序线索进行逆向中序遍历
void RevInorder(ThreadNode *T){
    for(ThreadNode *p=Lastnode(T);p!=NULL;p= Prenode(p)){
        visit(p);
    }
}


//分割线===================
//先序线索二叉树线序后继
//在中序线索二叉树中找到结点p的后继结点
ThreadNode *Prenode(ThreadNode *p){
    //右子树中最左下结点
    if(p->ltag==0){
        return Firstnode(p->lchild);//rtag==1没有右孩子，即有中序后继，rtag==0有右孩子，即没有中序后继
    } else{
        return  p->lchild;//rtag==1直接返回后继线索
    }
}
