#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<int> nums(n);
        bool find = false;
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        for(int i = 0;i<n;i++){
            if(nums[i] == 67){
                find = true;
                break;
            }
        }
        if(find){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}