#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size() && j != i; j++){
                if((nums[i]+nums[j]) == target){
                    result.push_back(j);
                    result.push_back(i);
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    int array_num, temp;
    vector<int> nums;
    int target;
    printf("length of array:\n");
    scanf("%d", &array_num);
    printf("input the array:\n");
    while(array_num>0){
        scanf("%d", &temp);
        nums.push_back(temp);
        array_num--;
    }
    printf("target:\n");
    scanf("%d", &target);
    Solution so;
    vector<int> result = so.twoSum(nums, target);
    printf("[%d, %d]\n", result[0], result[1]);
}