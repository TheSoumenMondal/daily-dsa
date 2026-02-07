#include<iostream>
#include<vector>
using namespace std;

vector<int> get_array_intersection(vector<int>&arr,vector<int>&brr){
    int i =0;
    int j =0;
    int n = arr.size();
    int m = brr.size();
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    vector<int> intersection_arr;
    while(i<n && j<m){
        if(arr[i] < brr[j]){
            i++;
        }else if(brr[j] < arr[i]){
            j++;
        }else{
            if(intersection_arr.size() ==0 || intersection_arr.back() != arr[i]){
                intersection_arr.push_back(arr[i]);
            }
            i++;
            j++;
        }
    }
    return intersection_arr;
}

void print_arr(vector<int>&arr){
    for(int it : arr) cout<<it<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,6,7,8,8,9,10};
    vector<int> brr = {1,1,2,2,3,4,5,5,6,6,6,6,6,6};
    vector<int> intersection_array = get_array_intersection(arr,brr);
    print_arr(intersection_array);
    return 0;
}