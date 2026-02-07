#include<iostream>
#include<vector>

int get_max_k_size_array_sum(std::vector<int>&nums,int k){
    int n = nums.size();
    int max_sum = 0;
    int sum = 0;
    for(int i =0;i<k;i++){
        sum+=nums[i];
    }
    int left_ptr = 0;
    int right_ptr = k;
    max_sum = sum;
    while(right_ptr<n){
        sum+=nums[right_ptr];
        sum-=nums[left_ptr];
        right_ptr++;
        left_ptr++;
        max_sum = std::max(max_sum , sum);
    }
    return max_sum;
}

int main(){
    std::vector<int>nums = {-1,2,3,3,4,5,-1};
    int k = 4;
    std::cout<<get_max_k_size_array_sum(nums,k);
    return 0;
}