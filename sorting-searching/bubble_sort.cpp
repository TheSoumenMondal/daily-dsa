#include<iostream>
#include<vector>

void bubble_sort(std::vector<int>&nums){
    int n = nums.size();
    for(int i = 0;i<n-1;i++){
        bool isSorted = true;
        for(int j = 0;j<n-i-1;j++){
            if(nums[j] > nums[j+1]){
                std::swap(nums[j] , nums[j+1]);
                isSorted = false;
            }
        }
        if(isSorted){
            break;
        }
    }
}

void print_arr(std::vector<int> & nums){
    for(auto it : nums){
        std::cout<<it<<" ";
    }
}


int main(){
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};
    bubble_sort(nums);
    print_arr(nums);
    return 0;
}