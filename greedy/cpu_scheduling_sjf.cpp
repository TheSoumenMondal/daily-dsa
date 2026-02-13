#include<iostream>
#include<vector>

int get_avg_waiting_time(std::vector<int> brust_times){
    int n = brust_times.size();
    int timer = 0;
    int waiting_time = 0;
    std::sort(brust_times.begin() , brust_times.end());
    for(int i =0;i<n;i++){
        waiting_time+=timer;
        timer+=brust_times[i];
    }
    return waiting_time/n;
}

int main(){
    std::vector<int>brust_times = {4,3,7,1,2};
    std::cout<<get_avg_waiting_time(brust_times);
    return 0;
}