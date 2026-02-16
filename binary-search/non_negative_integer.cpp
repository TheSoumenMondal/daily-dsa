#include<iostream>
#include<vector>

// So the idea it that if all number are present from 0 to n then all will be on the index itself , that menas the index == number
int find_first_missinng_number(std::vector<int>&nums){
    int low = 0;
    int high = nums.size() - 1;
    int index = -1;
    while(low <=high ){
        int mid = low + (high - low ) / 2;
        if(nums[mid] == mid){
            low = mid+1;
            index = mid;
        }else{
            high = mid-1;
        }
    }
    return index;
}

int main(){
    std::vector<int>nums = {0,1,2,3,4,57,58,59,100};
    std::cout<<find_first_missinng_number(nums);
    return 0;
}