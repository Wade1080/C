#define MaxSize 10 //静态链表的最大长度
typedef struct {//静态链表结构类型的定义
    ElemType data;//存储数据元素
    int next;//下一个元素的数组下标（游标）
}SLinkList[MaxSize];
void testSLinkList(){
//    struct Node a[MaxSize];
    SLinkList a;
}

//初始化静态链表：把a[0]的next设为-1，把其他节点的next设为一个特殊值用来表示节点空闲，如-2