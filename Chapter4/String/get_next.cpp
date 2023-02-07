//
// Created by Wade1080 on 2023/2/5.
//
void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            //若pi=pj,则next[j+1]=next[j]+1
            next[i]=j;
        } else
            //否则令j=next[j],循环继续
            j=next[j];
    }
}

//KMP算法
int Index_KMP(SString S,SString T){
    int i=1,j=1;
    int next[T.length+1];
    get_next(T,next);
    while (i<=S.length&&j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        } else
            j=next[j];
    }
if(j>T.lenth){
    return i-T.length;
} else
    return 0;
}