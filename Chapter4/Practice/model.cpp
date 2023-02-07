    //Index(S,T)：定位操作（模式匹配）。若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数值为0
    //朴素模式匹配算法
    // 在朴素模式匹配算法中，k代表当前检查的子串在主串S中的起始位置，j代表子串T在当前比较过程中已经匹配到的字符的位置。
    int Index(SString S,SString T){
        int k=1;//记录当检查的子串起始位置
        int i=k,j=1;
        while(i<=S.length&&j<=T.length){
            if(S.ch[i]==T.ch[j]){//头相同，继续比较后续元素
                ++i;
                ++j;//继续比较后继字符
            }
            else{
                k++;//检查下一个字符
                i=k;
                j=1;
            }
        }
        if(j>T.lenth)
            return k;
        else
            return 0;
    }
    //第二种实现
    int Index(SString S,SString T){
        int i=1,j=1;
        while(i<=S.length && j<=T.length){
            if(S.ch[i]==T.ch[j]){
                ++i;++j;//继续比较后继字符
            } else{
                i=i+2-j;//减少不必要的比较次数，往后推进
                j=1;
            }
        }
        if(j>T.length)
            return i-T.length;
        else
            return 0;
    }