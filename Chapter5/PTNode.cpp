//
// Created by Wade1080 on 2023/2/9.
//
#define MAX_TREE_SIZE 100 //树中最多结点数
typedef struct {
    ElemType data; //数据元素
    int parent;//双亲位置域
}PTNode;
typedef struct {//树的类型定义
    PTNode ndoes[MAX_TREE_SIZE];//双亲表示
    int n;//结点数
}PTree;
//分割线=====================================================

//树的先根遍历
void PreOrder (TreeNode *R){
    if(R!=NULL){
        visit(R);//访问根节点
        while(R还有下一个子树T){
            PreOrder(T);//先根遍历下一棵子树
        }
    }
}
//后根遍历。若树非空，先一次对每棵子树进行后根遍历，最后再访问根结点
void PostOrder(TreeNode *R){
    if(R!=NULL){
        while(R还有下一个子树T)
            PostOrder(T);//后根遍历下一棵子树；
        visit(T);//访问根节点
    }
}

//层次遍历（用队列实现）
//1. 若树非空，则根节点入队
//2. 若队列非空，队头元素出队并访问，同时该元素的孩子依次入队
//3. 重复2直到队列为空