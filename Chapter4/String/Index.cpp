//
// Created by Wade1080 on 2023/2/4.
//
int Index(SString S,SString T){
    int k =1 ;//k是代表子串
    int i=k,j=1;//i和j表示当前两个串（主串和待检测串）指针的位置
    while(i<=S.length&&j<=T.length){
        if(S.ch[i]==T.ch[i]){
            ++i;
            ++j;//继续比较后继字符
        }
        else{
            k++;
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
}