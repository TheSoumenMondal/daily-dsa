#include<iostream>
#include<vector>

int min_subarray_length(std::vector<int>&arr,int target){
    int i =0;
    int j = 0;
    int n = arr.size();
    int sum = 0;
    int min_length = INT_MAX;
    while(j<n){
        //expand the size of window
        sum+= arr[j];
        j++;
        //shrink the size of window while current sum if greater than target
        while(sum>=target){
            min_length = std::min(min_length , j-i);
            sum-=arr[i];
            i++;
        }
    }
    return min_length;
}

int main(){
    std::vector<int>nums = {2,3,1,2,4,3};
    int target = 7;
    std::cout<<min_subarray_length(nums,target);
    return 0;
}