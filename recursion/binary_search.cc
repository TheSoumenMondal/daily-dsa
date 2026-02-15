#include<iostream>

int recursive_binary_search(int target , int low ,int high , std::vector<int>&nums){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(nums[mid] == target){
        return mid;
    }else if( target < nums[mid]){
        return recursive_binary_search(target,low,mid-1 , nums);
    }
    return recursive_binary_search(target,mid+1,high , nums);
}

int binary_search(std::vector<int>&nums , int target){
    int low = 0;
    int high = nums.size() - 1;
    return recursive_binary_search(target , low , high , nums);
}

int main(){
    int target = 200;
    std::vector<int>nums = {90,100,200,300};
    std::cout<<binary_search(nums,target);
    return 0;
}