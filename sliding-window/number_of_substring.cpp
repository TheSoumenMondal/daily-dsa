#include<iostream>
#include<string>
#include<unordered_map>

int get_substring_cnt(std::string str){
    int left_ptr = 0;
    int right_ptr = 0;
    std::unordered_map<int,int>mpp;
    int n = str.length();
    int sub_string_cnt = 0;
    while(right_ptr<n){
        mpp[str[right_ptr]]++;
        while(mpp.size() == 3 ){
            sub_string_cnt+=(n-right_ptr);
            mpp[left_ptr]--;
            if(mpp[left_ptr] ==0){
                mpp.erase(left_ptr);
            }
            left_ptr++;
        }
        right_ptr++;
    }
    return sub_string_cnt;
}

int main(){
    std::string str = "aabcaabcccabc";
    std::cout<<get_substring_cnt(str)<<std::endl;
    return 0;
}