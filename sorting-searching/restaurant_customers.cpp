#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force Approach : TC -> O(n^2)
int get_max_person(std::vector<pair<int,int>>customers){
    int max_cnt = 0;
    int n = customers.size();
    sort(customers.begin(),customers.end());
    for(int i =0;i<n;i++){
        pair<int,int> curr = customers[i];
        int enter_time = curr.first;
        int leaving_time = curr.second;
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(customers[j].first <= enter_time && customers[j].second > enter_time){
                cnt++;
            }
        }
        max_cnt = max(max_cnt , cnt);
    }
    return max_cnt;
}


// Use the sweep line algorithm

int get_max_persons(vector<pair<int,int>>&customers){
    sort(customers.begin(),customers.end());
    int cnt =0;
    int max_cnt =0;
    for(auto it : customers){
        cnt+= it.second;
        max_cnt = max(max_cnt , cnt);
    }
    return max_cnt;
}


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> customers;
    for(int i =0;i<n;i++){
        int a , b;
        cin>>a>>b;
        customers.push_back({a,1});
        customers.push_back({b,-1});
    }
    cout<<get_max_persons(customers);

    // vector<pair<int,int>> customers;
    // for(int i = 0; i < n; i++){
    //     int a, b;
    //     cin >> a >> b;
    //     customers.push_back({a, b});
    // }
    // cout << get_max_person(customers);

    return 0;
}