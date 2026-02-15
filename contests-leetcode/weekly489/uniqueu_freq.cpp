#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int first_uniqueu_freq(vector<int>&nums){
    // Step 1: Count frequency of each element
    unordered_map<int,int>mpp;
    for(auto it : nums){
        mpp[it]++;
    }

    // Step 2: Count how many elements share each frequency
    unordered_map<int,int>freq_count;
    for(auto& it : mpp){
        freq_count[it.second]++;
    }

    // Step 3: Scan left to right, return first element whose frequency is unique
    for(auto it : nums){
        if(freq_count[mpp[it]] == 1){
            return it;
        }
    }

    return -1;  
}

int main(){
    vector<int>nums1 = {20, 10, 30, 30};
    cout << first_uniqueu_freq(nums1) << endl; // 30

    vector<int>nums2 = {20, 20, 10, 30, 30, 30};
    cout << first_uniqueu_freq(nums2) << endl; // 20

    vector<int>nums3 = {10, 10, 20, 20};
    cout << first_uniqueu_freq(nums3) << endl; // -1

    vector<int>nums4 = {20, 20, 30, 30, 30, 40, 40, 40, 50};
    cout << first_uniqueu_freq(nums4) << endl;

    return 0;
}