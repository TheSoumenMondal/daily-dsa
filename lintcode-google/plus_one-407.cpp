#include<iostream>
#include<vector>

void print_arr(std::vector<int>nums){
    for(auto it : nums){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}

std::vector<int> plus_one(std::vector<int> &digits) {
    // write your code here
    std::vector<int>ans;
    int carry = 1;
    int n = digits.size();
    //O(n)
    for(int i = n-1;i>=0;i--){
        int sum = digits[i] + carry;
        int rem = sum % 10;
        ans.push_back(rem);
        carry = sum / 10;
    }
    if(carry){
        ans.push_back(carry);
    }
    int start =0;
    int end = ans.size() - 1;
    //O(n)
    while(start <= end){
        int temp = ans[start];
        ans[start] = ans[end];
        ans[end] = temp;
        start++;
        end--;
    }
    return ans;
}

int main(){
    std::vector<int>nums = {9};
    std::vector<int>ans = plus_one(nums);
    print_arr(ans);
    return 0;
}