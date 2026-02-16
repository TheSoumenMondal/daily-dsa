#include<iostream>
#include<vector>

bool helper(std::vector<int>&nums , int start_index){
    if(start_index >= nums.size() -1){
        return true;
    }
    if(nums[start_index] > nums[start_index+1]){
        return false;
    }
    return helper(nums,start_index+1);
}

bool is_array_sorted(std::vector<int>&nums){
    return helper(nums,0);
}

int main(){
    std::vector<int>num = {10, 20, 10, 40, 50};
    std::cout<<is_array_sorted(num);
    return 0;
}