#include<iostream>
#include<vector>

int max_subarray_sum(std::vector<int>&arr){
    int max_sum = INT_MIN;
    int sum = 0;
    for(int i =0;i<arr.size();i++){
        sum+=arr[i];
        //Remember to update the max first then reinitialize to 0 if less than 0 
        max_sum = std::max(max_sum , sum);
        if(sum<0) sum =0;
    }
    return max_sum;
}

int main(){
    std::vector<int>nums = {-1};
    std::cout<<max_subarray_sum(nums);
    return 0;
}