#include<iostream>
#include<vector>

int helper_fun(std::vector<int>nums , int start_index , int target){
    if(start_index == nums.size()) return -1;
    if(nums[start_index] == target) return start_index;
    return helper_fun(nums,start_index+1,target);
}

int linear_search(std::vector<int>nums , int target){
    return helper_fun(nums,0,target);
}

int main(){
    std::vector<int>nums = {10,20,40,30,60,90,100,102,13};
    int target = 100;
    std::cout<<linear_search(nums,target);
    return 0;
}