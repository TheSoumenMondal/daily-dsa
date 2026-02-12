// sweep line algoritm
// Company : Google , Amazon
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Interval {
    public : 
    int start , end;
    Interval(int start , int end){
        this->start = start;
        this->end = end;
    }
};

bool compare_adjucent(Interval &a , Interval &b){
    return a.start < b.start;
}

void reverse_interval_array(vector<Interval> &intervals){
    int start =0;
    int end = intervals.size() -1;
    while(start <= end){
        Interval temp = intervals[start];
        intervals[start] = intervals[end];
        intervals[end] = temp;
        start++;
        end--;
    }
}

void print_test(vector<Interval> &test){
    for(auto it : test){
        cout<<"("<<it.start<<","<<it.end<<")"<<" ";
    }
    cout<<endl;
}

vector<Interval> merge(vector<Interval> &intervals) {
    //O(nlogn)
    if(intervals.size() == 0){
        return intervals;
    }
    sort(intervals.begin(),intervals.end(),compare_adjucent);
    stack<Interval>st;
    vector<Interval>ans;
    st.push(intervals[0]);
    int second_ptr = 1;
    int n = intervals.size();
    // O(2n)
    while(second_ptr<n){
        while(!st.empty() && second_ptr<n && st.top().end >= intervals[second_ptr].start){
            Interval top_element = st.top();
            st.pop();
            Interval *newinterval = new Interval(min(top_element.start ,intervals[second_ptr].start ) , max(intervals[second_ptr].end , top_element.end));
            st.push(Interval(newinterval->start , newinterval->end));
            second_ptr++;
        }
        if(second_ptr < n) st.push(intervals[second_ptr]);
        second_ptr++;
    }
    //O(n)
    while(!st.empty()){
        Interval top = st.top();
        st.pop();
        ans.push_back(top);
    }
    //reverse O(n)
    reverse_interval_array(ans);
    return ans;
}



int main(){
    vector<Interval> test1 = {Interval(2,3), Interval(2,2), Interval(3,3), Interval(1,3), Interval(5,7), Interval(2,2), Interval(4,6)};
    vector<Interval> ans = merge(test1);
    print_test(ans);
    return 0;
}