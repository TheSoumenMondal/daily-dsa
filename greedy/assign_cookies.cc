#include<iostream>
#include<vector>
#include<algorithm>

//overall time complexity : O(nlogn)
int max_satisfied_children(std::vector<int>&greed_factor , std::vector<int>&size){
    //TC : O(nlogn)
    std::sort(greed_factor.begin() ,greed_factor.end());
    //TC : O(nlogn)
    std::sort(size.begin() ,size.end());
    int g_ptr = 0;
    int s_ptr = 0;
    int satisfied_child_cnt = 0;
    //O(max(greed.size() , size.size()))
    while(g_ptr < greed_factor.size() && s_ptr < size.size()){
        if(size[s_ptr] >= greed_factor[g_ptr]){
            g_ptr++;
            satisfied_child_cnt++;
        }
        s_ptr++;
    }
    return satisfied_child_cnt;
}

int main(){
    std::vector<int>greed_factor = {1,2};
    std::vector<int>size ={1,2,3};
    std::cout<<max_satisfied_children(greed_factor , size);
    return 0;
}