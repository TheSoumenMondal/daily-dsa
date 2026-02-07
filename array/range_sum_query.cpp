#include<iostream>
#include<vector>

std::vector<int> range_sum_query(std::vector<int>& nums,std::vector<std::pair<int,int>>&queries){
    std::vector<int>range_query_sum;
    // Convert the array to prefix_sum array
    int n = nums.size();
    for(int i = 1;i<n;i++){
        nums[i] = nums[i] + nums[i-1];
    }
    for(int i = 0 ;i< queries.size();i++){
        int left = queries[i].first;
        int right = queries[i].second;
        if(left ==0){
            range_query_sum.push_back(nums[right]);
        }else{
            int sum = nums[right] - nums[left-1];
            range_query_sum.push_back(sum);
        }
    }
    return range_query_sum;
}

void print_arr(std::vector<int>&nums){
    for(int num : nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int> nums = {-2,0,3,-5,2,-1};
    std::vector<std::pair<int,int>>queries = {{0,2},{2,5},{0,5}};
    std::vector<int>ans = range_sum_query(nums,queries);
    print_arr(ans);
    return 0;
}