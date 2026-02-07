#include<iostream>
#include<vector>
using namespace std;

// As the array is sorted use the two pointer approach , while they are in range and the ans array's last element does not equal to the current element then push the current element into the answer array otherwise ignore it.
// Check it when ever you are pushing element into your answer array as one array can have duplicate elements.

vector<int>sorted_array_union(vector<int>&arr , vector<int>&brr){
    int i =0;
    int j = 0;
    int n = arr.size();
    int m = brr.size();
    vector<int>merged_arr;
    while(i<n and j< m){
        if(arr[i]<brr[j]){
            if(merged_arr.empty() or merged_arr.back() != arr[i]){ 
                merged_arr.push_back(arr[i]);
            }
            i++;
        }else if(brr[j] < arr[i]){
            if(merged_arr.empty() or merged_arr.back() != brr[j]){
                merged_arr.push_back(brr[j]);
            }
            j++;
        }else{
            if(merged_arr.empty() or merged_arr.back() != arr[i]){
                merged_arr.push_back(arr[i]);
            }
            i++;
            j++;
        }
    }
    while(i<n){
        if(merged_arr.empty() || merged_arr.back() != arr[i]){
            merged_arr.push_back(arr[i]);
        }
        i++;
    }
    while(j<m){
        if(merged_arr.empty() || merged_arr.back() != brr[j]){
            merged_arr.push_back(brr[j]);
        }
        j++;
    }
    return merged_arr;
}

void print_arr(vector<int>arr){
    for(int element : arr){
        cout<<element <<' ';
    }
    cout<<'\n';
}

int main(){
    vector<int>arr1 = {1,2,3,4,4,5,5,5,5,5,6,8};
    vector<int>arr2 = {2,3,4,5,6};
    vector<int>union_arr = sorted_array_union(arr1,arr2);
    print_arr(union_arr);
    return 0;
}