#define MaxSize 10 //定义栈中的最大个数
typedef struct {
    ElemType data[MaxSize];//静态数组存放栈中元素
    int top;//栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top=-1;//初始化栈顶指针
}

bool StackEmpty(SqStack S){
    if(S.top==-1)//栈空
        return true;
    else
        return false;//不空
}


//新元素入栈
bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1)
        return false;
    S.top=S.top+1;//指针先加1
    S.data[S.top]=x;//新元素入栈
    return true;
}

//出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1)
        return false;
    x=S.data[S.top];//栈顶元素先出栈
    S.top=S.top-1;//指针再减1
    //也可以写成x=S.data[S.top--];先出栈，指针再减1
    return true;
}


//读栈顶元素
bool GetTop(SqStack S,ElemType &x){
    if(S.top==-1)
        return false;
    x=S.data[S.top];//x记录栈顶元素
    return true;
}


void testStack(){
    SqStack S;//声明一个顺序栈（分配空间）
    InitStack(S);
}



//共享栈
typedef struct {
    ElemType data[MaxSize];
    int top0;//0号栈栈顶指针
    int top1;//1号栈栈顶指针
}ShStack;

//初始化栈
void InitStack(ShStack &S){
    S.top0=-1;//初始化栈顶指针
    S.top1=MaxSize;
}//栈满条件：top0+1==top1