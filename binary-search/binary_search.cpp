#include<iostream>
#include<vector>

int binary_search(std::vector<int>&nums , int target){
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = low + (high - low) /2;
        if(nums[mid] == target){
            return mid;
        }else if(target > nums[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    std::vector<int>num = {12,14,15,16,17,18,90,92};
    int target = 18;
    std::cout<<binary_search(num,target);
    return 0;
}