#include<iostream>
#include<vector>
#include<algorithm>

class Interval{
    public:
    int start , end;
    Interval(int start , int end){
        this->start = start;
        this->end = end;
    }
};

bool compare_adjucent(std::pair<int,int> &a , std::pair<int,int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int min_meeting_rooms(std::vector<Interval>& intervals) {
    std::vector<std::pair<int,int>> helper_arr;
    for(Interval interval : intervals){
        helper_arr.push_back({interval.start , 1});
        helper_arr.push_back({interval.end , -1});
    }

    std::sort(helper_arr.begin() , helper_arr.end() , compare_adjucent);

    int cnt = 0;
    int max_cnt = 0;

    for(std::pair<int,int> it : helper_arr){
        cnt+=it.second;
        max_cnt = std::max(max_cnt , cnt);
    }
    return max_cnt;
}

int main(){
    std::vector<Interval> intervals = {
        Interval(4,9),
        Interval(5,10),
        Interval(10,15),
        Interval(15,20),
        Interval(20,25),
        Interval(25,35),
        Interval(12,40),
        Interval(30,50),
        Interval(45,60),
        Interval(55,70),
        Interval(65,80),
        Interval(75,90),
        Interval(85,100),
        Interval(1,99),
        Interval(2,98),
        Interval(3,97),
        Interval(4,96),
        Interval(6,95)
    };

    std::cout<<min_meeting_rooms(intervals);
    return 0;
}