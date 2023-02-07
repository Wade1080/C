#include <iostream>
#define MaxSize 10            //定义队列中元素的最大个数
typedef struct {
    ElemType data[MaxSize];//用静态数组存放队列元素
    int front,rear;//队头指针和队尾指针
}SqQueue;
//初始化队列
void InitQueue(SqQueue &Q){
    //初始化 队头、队尾指针指向0
    Q.rear=Q.front=0;
}

void testQueue(){
    //声明一个队列（顺序存储）
    SqQueue Q;
    InitQueue(Q);
}


//判断队列是否为空
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front) //队空条件：头指针等于尾指针（一般初始化一个空队列的时候，头指针跟尾指针都在队列头）
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x){
    if(队列满)
        return false;
    Q.data[Q.rear]=x;//将x插入队尾
    Q.rear=Q.rear+1;//队尾指针后移
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
