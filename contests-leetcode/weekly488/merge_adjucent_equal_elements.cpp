#include<iostream>
#include<vector>
#include<stack>

void reverse(std::vector<long long>& nums){
    long long start =0;
    long long end = nums.size() - 1;
    while(start <= end){
        long long temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

std::vector<long long> merge_adjucent_equal_elements(std::vector<int>&nums){
    std::stack<long long>st;
    int n = nums.size();
    st.push(nums[0]);
    for(int i =1;i<n;i++){
        long long top = st.top();
        if(nums[i] == top){
            st.pop();
            long long element = 2LL * nums[i];
            while(!st.empty() and st.top() == element){
                st.pop();
                element = 2LL * element;
            }
            st.push(element);
            continue;
        }
        st.push(nums[i]);
    }

    std::vector<long long>ans;
    while(!st.empty()){
        long long top = st.top();
        st.pop();
        ans.push_back(top);
    }
    reverse(ans);
    return ans;
}

int main(){
    std::vector<int> nums = {3,1,1,2};
    std::vector<long long> ans = merge_adjucent_equal_elements(nums);
    for(auto it : ans){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}