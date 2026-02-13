#include<iostream>
#include<vector>

void insertion_sort(std::vector<int> &nums){
    int n = nums.size();
    for(int i = 1;i<n;i++){
        int element = nums[i];
        int index = i-1;
        while(index >=0 && nums[index] > element){
            nums[index+1] = nums[index];
            index--;
        }
        nums[index+1] = element;
    }
}

void print_arr(std::vector<int> & nums){
    for(auto it : nums){
        std::cout<<it<<" ";
    }
}

int main(){
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};
    insertion_sort(nums);
    print_arr(nums);
    return 0;
}