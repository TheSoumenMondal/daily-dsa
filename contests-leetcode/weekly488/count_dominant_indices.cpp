#include<iostream>
#include<vector>

void print_arr(std::vector<int>&arr){
    for(auto it : arr){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}

int dominant_indices(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int>suffixArray(n,0);
    for(int i = n-2;i>=0;i--){
        suffixArray[i] = nums[i+1] + suffixArray[i+1];
    }
    
    // print_arr(suffixArray);
    
    for(int i = n-2 ;i>=0;i--){
        suffixArray[i] = suffixArray[i] / (n-i-1);
    }
    
    // print_arr(suffixArray);

    int cnt = 0;

    for(int i =0;i<n-1;i++){
        if(nums[i] > suffixArray[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    std::vector<int> nums = {5, 3, 2, 4, 1};
    std::cout<<dominant_indices(nums);
    return 0;
}
