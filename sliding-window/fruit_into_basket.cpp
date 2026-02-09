#include<iostream>
#include<vector>
#include<unordered_map>

int total_fruits(std::vector<int>& fruits){
    int n = fruits.size();
    int left_ptr = 0;
    int right_ptr = 0;
    int max_len = 0;
    std::unordered_map<int,int>mpp;
    while(right_ptr <n){
        mpp[fruits[right_ptr]]++;
        while(mpp.size() > 2){
            mpp[fruits[left_ptr]]--;
            if(mpp[fruits[left_ptr]] == 0){
                mpp.erase(fruits[left_ptr]);
            }
            left_ptr++;
        }
        max_len = std::max(max_len , right_ptr - left_ptr + 1);
        right_ptr++;
    }
    return max_len;
}

int main(){
    std::vector<int> fruits = {1,2,3,2,2};
    std::cout<<total_fruits(fruits);
    return 0;
}