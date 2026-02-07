#include<iostream>
#include<vector>

void dutch_national_flag_algo(std::vector<int>&arr){
    int n = arr.size();
    int lowPtr = 0;
    int midPtr = 0;
    int highPtr = n-1;
    while(midPtr <= highPtr){
        if(arr[midPtr] == 0){
            int temp = arr[lowPtr];
            arr[lowPtr] = arr[midPtr];
            arr[midPtr] = temp;
            lowPtr++;
            midPtr++;
        }else if(arr[midPtr] ==1){
            midPtr++;
        }else{
            int temp = arr[midPtr];
            arr[midPtr] = arr[highPtr];
            arr[highPtr] = temp;
            highPtr--;
        }
    }
}

void print_arr(std::vector<int>&nums){
    for(int num :  nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int> nums = {0,0,1,1,0,2,2,0,1,0,0,0,1,1,1,1,1,2,2,2};
    dutch_national_flag_algo(nums);
    print_arr(nums);
    return 0;
}