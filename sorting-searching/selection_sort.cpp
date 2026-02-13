#include<iostream>
#include<vector>

void find_minimum_and_swap(std::vector<int>&nums , int start){
    int min_index = start;
    for(int i = start + 1;i<nums.size();i++){
        if(nums[i] < nums[min_index]){
            min_index = i;
        }
    }
    std::swap(nums[start] , nums[min_index]);
}

void selection_sort(std::vector<int>& nums){
    int n = nums.size();
    for(int i =0;i<n-1;i++){
        find_minimum_and_swap(nums,i);
    }
}

void print_arr(std::vector<int> & nums){
    for(auto it : nums){
        std::cout<<it<<" ";
    }
}

int main(){
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    selection_sort(arr);
    print_arr(arr);
    return 0;
}