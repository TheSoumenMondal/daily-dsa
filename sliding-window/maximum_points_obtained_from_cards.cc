#include<iostream>
#include<vector>

int get_max_obtained_points(std::vector<int>&nums,int k){
    int n = nums.size();
    int left_sum = 0;
    for(int i =0;i<k;i++){
        left_sum+=nums[i];
    }
    int max_sum = left_sum;
    int right_sum =0;
    int end = n-1;
    for(int i = k-1;i>=0;i--){
        right_sum +=nums[end--];
        left_sum = left_sum - nums[i];
        max_sum = std::max(max_sum,left_sum + right_sum);
    }
    return max_sum;
}

int main(){
    std::vector<int>cardPoints = {9,7,7,9,7,7,9};
    int k = 7;
    std::cout<<get_max_obtained_points(cardPoints,k);
    return 0;
}