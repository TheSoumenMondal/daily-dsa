#include<iostream>
#include<vector>

int lower_bound(std::vector<int>&nums ,int x){
    int low = 0;
    int high = nums.size()  -1;
    int index = -1;
    while(low <= high ){
        int mid = low + (high - low) / 2;
        if( nums[mid] >= x){
            index = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return index;
}


int upper_bound(std::vector<int>&nums , int x){
    int low = 0;
    int high = nums.size() - 1;
    int index = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > x) {
            index = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return index;
}

int main(){
    std::vector<int>nums = {1,2,3,3,4,5,6,7,8,9,9,10};
    std::cout<<lower_bound(nums,9)<<std::endl;
    std::cout<<upper_bound(nums,9)<<std::endl;
    return 0;
}