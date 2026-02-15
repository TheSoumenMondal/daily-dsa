#include<iostream>
#include<vector>
using namespace std;

bool can_be_sorted(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int index = i + 1;
        int value = nums[i];
        while (index % 2 == 0) index /= 2;
        while (value % 2 == 0) value /= 2;
        if (index != value) return false;
    }
    return true;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        if(can_be_sorted(nums)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}