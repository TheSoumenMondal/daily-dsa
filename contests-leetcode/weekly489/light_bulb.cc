#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> solve(vector<int>&bulbs){
    map<int,int>mpp;
        int n = bulbs.size();
        for(auto it : bulbs){
            mpp[it]++;
        }
        vector<int>ans;
        for(auto it : mpp){
            if(it.second % 2 != 0){
                ans.push_back(it.first);
            }
        }

        sort(ans.begin() , ans.end());

        return ans;
}

int main(){
    vector<int> bulbs = {10,20,30,10};
    vector<int> result = solve(bulbs);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}