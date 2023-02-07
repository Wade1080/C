//
// Created by Wade1080 on 2023/2/4.
//
int Index_KMP(SString S,SString T,int next[]){
    int i = 1,j=1;
    while (i<=S.length&&j<=T.length){
        if(j==0|S.ch[i]==T.ch[j]){
            ++i;
            ++j;//继续比较后继字符
        } else
            j=next[j];//next[1]=0;是为了方便后续循环中的条件判断
    }
    if(j>T.lenth)
        return i-T.length;
    else
        return 0;
}
//模式串的前缀：包含第一个字符，且不包含最后一个字符的子串
//主串的后缀：包含最后一个字符，且不包含第一个字符的子串
//当第j个字符匹配失败，由前1~j-1的字符组成的串记为S，则：next[j]=S的（最长且相等）的前后缀长度+1