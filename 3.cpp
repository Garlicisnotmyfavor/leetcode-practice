class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //特殊用例
        if(s.size() == 0) return 0;
        int max = 1;
        int front = 0, rear = 1;
        int length = s.size();
        for(int i=1; i<length; i++){
            int j;
            //判断下一个字符是否可以加入，即判断是否有重复
            for(j=front; j<rear; j++){
                if(s[j] == s[rear]){
                    //发现新加入的和前面的串有相等的，移动front位置
                    front = j+1;
                    rear++;
                    break;
                }
            }
            //循环完毕都没有发现相同的字符，则rear移动
            if(j == rear) rear++;
            //判断是否需要更新max
            if((rear-front) > max) max = rear-front;
        }
        return max;
    }
};