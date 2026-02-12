#include<iostream>
#include<vector>

void print_interval(std::vector<std::vector<int>> &intervals){
    for(int i =0;i<intervals.size();i++){
        std::cout<<"("<<intervals[i][0]<<","<<intervals[i][1]<<")"<<std::endl;
    }
}


std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)    {
    std::vector<std::vector<int>> new_intervals;
    int i = 0;
    int n = intervals.size();
    while(i<n && intervals[i][1] < newInterval[0]){
        new_intervals.push_back(intervals[i]);
        i++;
    }

    std::vector<int>merged_interval = newInterval;

    while( i < n && intervals[i][0] <= merged_interval[1]){
        merged_interval[0] = std::min(merged_interval[0] , intervals[i][0]);
        merged_interval[1] = std::max(merged_interval[1] , intervals[i][1]);
        i++;
    }


    new_intervals.push_back(merged_interval);


    for(int j = i;j<n;j++){
        new_intervals.push_back(intervals[j]);
    }

    return new_intervals;

}


int main(){
    std::vector<std::vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int>newInterval = {4,8};
    std::vector<std::vector<int>> new_intervals = insert(intervals,newInterval);
    print_interval(new_intervals);
    return 0;
}