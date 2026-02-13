#include<iostream>
#include<vector>

void print_arr(std::vector<int>&nums){
    for(int i =0;i<nums.size();i++){
        std::cout<<nums[i]<<std::endl;
    }
    std::cout<<std::endl;
}

std::vector<int> range_sum_array(std::vector<std::vector<int>>&operations ,int len){
    std::vector<int>arr(len , 0);
    // Perfome the difference array technique
    for(int i =0;i<operations.size();i++){
        int left_range = operations[i][0];
        int right_range = operations[i][1];
        int increment_factor = operations[i][2];
        arr[left_range] += increment_factor;
        if(right_range+1<len){
            arr[right_range + 1] -=increment_factor;
        }
    }

    // calculate the prefix sum

    for(int i =1;i<len;i++){
        arr[i]+=arr[i-1];
    }

    return arr;

}

int main(){
    int len = 5;
    std::vector<std::vector<int>> operations = {{1,3,2}, {2,4,3}, {0,2,-2}};
    std::vector<int>ans = range_sum_array(operations,len);
    print_arr(ans);
    return 0;
}