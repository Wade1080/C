//用数组操作和top指针完成该问题


#define MaxSize 10//定义栈中元素的最大个数
typedef struct {
    char data[MaxSize]; //静态数组存放栈中元素
    int top;//栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack s){

};

//判断栈是否为空
bool StackEmpty(SqStack S){

}

//入栈
bool Push(SqStack s, char i) {

}
//出栈
bool Pop(SqStack &S,char x){

};


bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);//初始化一个栈
    for (int i = 0; i < length; ++i) {
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(S,str[i]);//扫描到左括号，入栈
        }else{
            if(StackEmpty(S)) //扫描到右括号，且当前栈空
                return false;//匹配失败


            char topElem;
            Pop(S,topElem);//栈顶元素出栈
            if(str[i]==')'&&topElem!='(')
                return false;
            if(str[i]==']'&&topElem!='[')
                return false;
            if(str[i]=='}'&&topElem!='{')
                return false;
        }
    }
    return StackEmpty(S);//检索完全部括号后，栈空说明匹配成功





}

//栈顶元素出栈，用x返回
bool Pop(SqStack &S,char &x){

}
