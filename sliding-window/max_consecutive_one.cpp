#include<iostream>
#include<vector>

int get_max_consecutive_one(std::vector<int>&nums){
    int n = nums.size();
    int left_ptr = 0,right_ptr =0;
    int max_len = 0;
    int zero_cnt =0;
    int prev_zero_ptr =0;
    while(right_ptr<n){
        if(nums[right_ptr] == 0){
            if(zero_cnt == 1){
                left_ptr = prev_zero_ptr + 1;
            }
            zero_cnt = 1;
            prev_zero_ptr = right_ptr;
        }
        max_len = std::max(max_len , right_ptr - left_ptr + 1);
        right_ptr++;
    }
    return max_len;
}

int main(){
    std::vector<int>arr = {1,0,1,1,0};
    std::cout<<get_max_consecutive_one(arr);
    return 0;
}