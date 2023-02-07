#define MAXLEN 255 //预定义最大串长为255
//串的顺序存储用两种不同的存储结构实现
//1. 静态存储
typedef struct {
    char ch[MAXLEN];//每个分量存储一个字符
    int length;//串地实际长度
}SString;


//2. 动态存储
typedef struct {
    char *ch;//按串长分配存储区,ch指向串地基地址
    int length;//串的长度
}HString;

HString S;
H.ch = (char *)malloc(MAXLEN*sizeof(char));
S.length=0;


//串的链式存储
//1. 缺点：存储密度低，每个字符1B，每个指针4B
typedef struct StringNode{
    char ch;//每个结点存一个字符
    struct StringNode *next;
}StringNode,* String;

//存储密度高
typedef struct StringNode{
    char ch[4];//每个结点存多个字符
    struct StringNode *next;
}StringNode,* String;


//求子串
bool SubString(SString &Sub,SString S,int pos,int len){
    //子串范围越界
    if(pos+len-1>S.length)//pos是指位置,加上len后与表长进行比较
        return false;
    for (int i = pos; i < pos+len; i++) {
        Sub.ch[i-pos+1]=S.ch[i];
        return true;
    }

}


//比较操作。若S大于T，则返回值为正值，等值则返回0，小于则返回负值
int StrCompare(SString S,SString T){
    for (int i = 1; i <= S.length&&i<T.length; i++) {
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    //扫描过的所有字符都相同，则长度长的串更大
    return S.length-T.length;
}


//定位操作
int Index(SString S,SString T){
    int i=1,n=StrLength(S),m=StrLength(T);
    SString sub;//用于暂存子串
    while(i<n-m+1){
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0)
            ++i;
        else
            return i;//返回子串在主串中的位置
    }
    return 0;//S中不存在与T相等的子串
}