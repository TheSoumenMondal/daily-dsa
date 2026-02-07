#include<iostream>
#include<vector>

int get_mejority_element(std::vector<int>nums){
    int cnt = 1;
    int n = nums.size();
    int element = nums[0];
    for(int i =1 ;i<n;i++){
        //if cnt == 0 then assign the current element to the element
        if(cnt ==0){
            element = nums[i];
        }
        // if current element is equals to element increase the count else decrese cnt
        if(nums[i] == element){
            cnt++;
        }else{
            cnt--;
        }
    }
    //checking if element appears more than n/2 times
    int total_cnt =0;
    for(int i =0;i<n;i++){
        if(nums[i] == element){
            total_cnt++;
        }
    }
    if(total_cnt > (n/2)){
        return element;
    }
    return -1;
}

int main(){
    std::vector<int> arr = {6,5,5};
    std::cout<<get_mejority_element(arr);
    return 0;
}