#include<iostream>
#include<vector>

std::vector<std::pair<int,int>>flatten_and_sort(std::vector<std::vector<int>>&logs){
    int n = logs.size();
    std::vector<std::pair<int,int>> flatten_arr;
    for(int i =0;i<n;i++){
        flatten_arr.push_back({logs[i][0] , 1});
        flatten_arr.push_back({logs[i][1] ,-1});
    }
    std::sort(flatten_arr.begin() , flatten_arr.end());
    return flatten_arr;
}

int get_max_population_year(std::vector<std::vector<int>>&logs){
    std::vector<std::pair<int,int>> flatten_arr = flatten_and_sort(logs);
    int max_birth_year = logs[0][0];
    int cnt = 0;
    int max_birth_cnt = 0;
    for(auto it : flatten_arr){
        cnt+=it.second;
        if(cnt > max_birth_cnt){
            max_birth_year = it.first;
        }
        max_birth_cnt = std::max(max_birth_cnt,cnt);
    }
    return max_birth_year;
}

int main(){ 
    std::vector<std::vector<int>> logs = {{1950,1961},{1960,1971},{1970,1981}};
    std::cout<<get_max_population_year(logs);
    return 0;
}