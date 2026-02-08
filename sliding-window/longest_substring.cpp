#include<iostream>
#include<string>
#include<vector>

int get_longest_substring(std::string &str){
    int left_ptr = 0;
    int right_ptr = 0;
    int max_len = 0;
    int n = str.length();
    std::vector<int>vis(256,-1);
    while(right_ptr < n){
        if(vis[str[right_ptr]] != -1 && vis[str[right_ptr]] >=left_ptr){
            left_ptr = vis[str[right_ptr]] + 1;
        }
        max_len = std::max(max_len , right_ptr - left_ptr + 1 );
        vis[str[right_ptr]] = right_ptr;
        right_ptr++;
    }
    return max_len;
}

int main(){
    std::string str = "abcabcbb";
    std::cout<<get_longest_substring(str);
    return 0;
}