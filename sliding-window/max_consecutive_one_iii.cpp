#include<iostream>
#include<vector>

int get_max_consecutive_one(std::vector<int>&nums , int k){
    int n = nums.size();
    int left_ptr = 0;
    int right_ptr = 0;
    int max_len = 0;
    int zero_cnt =0;
    while(right_ptr < n){
        if(nums[right_ptr] ==0) zero_cnt++;
        while(zero_cnt>k){
            if(nums[left_ptr] == 0){
                zero_cnt--;
            }
            left_ptr++;
        }
        max_len = std::max(max_len , right_ptr - left_ptr + 1);
        right_ptr++;
    }
    return max_len;
}

int main(){
    std::vector<int>arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    std::cout<<get_max_consecutive_one(arr,k);
    return 0;
}