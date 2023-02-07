#define MaxSize 10
typedef struct {
    ElemType data[MaxSize];
    int front,rear;//队头指针和队尾指针
}SqQueue;
bool QueueEmpty(SqQueue Q){
    if(Q.rear==Q.front)//队空条件
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize==Q.front)
        return false;//队满则报错
    Q.data[Q.rear]=x;//新元素插入队尾
    Q.rear=(Q.rear+1)%MaxSize;//队尾指针加1取模，用模运算将储存空间在逻辑上变成了环状
    return true;
}

//出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front)
        return false;//队空则报错
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}


//获得队头元素的值，用x返回
bool GetHead (SqQueue Q,ElemType &x){
    if(Q.rear==Q.front)
        return false;//队空则报错
    x=Q.data[Q.front];
    return true;
}