class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result = 0;
        int temp = 0; //记录连续的最大长度
        int sm = 0;
        //争对不同类型的数据做分类
        for(int i=0; i<A.size(); i++){
            if(A[i]<L){
                temp++;
                sm++;
                if(i==(A.size()-1)){
                    result += temp*(temp+1)/2;
                    result -= sm*(sm+1)/2;
                }
            }else if(A[i]>R){
                result += temp*(temp+1)/2;
                result -= sm*(sm+1)/2;
                sm = 0;
                temp = 0;
            }else{
                temp++;
                result -= sm*(sm+1)/2;
                sm = 0;
                if(i==(A.size()-1)) result += temp*(temp+1)/2;
            }
            //printf("i:%d A[i]:%d temp:%d result:%d\n", i,A[i],temp,result);
        }
        return result;
    }
};