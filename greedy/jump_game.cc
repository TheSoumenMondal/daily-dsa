#include<iostream>
#include<vector>

bool can_reach_end(std::vector<int>&jump_points){
    int max_index = 0;
    int n = jump_points.size();
    for(int i =0;i<n-1;i++){
        if(i > max_index){
            return false;
        }
        int max_possible_jump = i + jump_points[i];
        max_index = std::max(max_index , max_possible_jump);
    }
    return max_index >= n-1;
}

int main(){
    std::vector<int>jump_poins = {2,0,1,0,4};
    std::cout<<can_reach_end(jump_poins);
    return 0;
}