#include<iostream>
#include<vector>
#include<set>


// when you only need the number of uniqueu elemenets
// int remove_duplicate(std::vector<int>&nums){
//     std::set<int>st;
//     for(int num : nums){
//         st.insert(num);
//     }
//     return st.size();
// }

int remove_duplicate(std::vector<int>&nums){
    int unique_index = 0;
    for(int i =0;i<nums.size();i++){
        if(nums[unique_index] != nums[i]){
            std::swap(nums[unique_index + 1] , nums[i]);
            unique_index++;
        }
    }
    return unique_index+1;
}

int main(){
    std::vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    std::cout<<remove_duplicate(nums);
    return 0;
}