#include<iostream>
#include<vector>
#include<algorithm>

int get_minimum_gondolas(std::vector<int>&weights , int max_allowed_weight){
    int cnt = 0;
    int n = weights.size();
    std::sort(weights.begin(),weights.end());
    int left_ptr = 0;
    int right_ptr = n-1;
    while(left_ptr <= right_ptr){
        if(weights[left_ptr] + weights[right_ptr] <= max_allowed_weight){
            left_ptr++;
            right_ptr--;
        }else{
            right_ptr--;
        }
        cnt++;
    }
    return cnt;
}

int main(){
    int n,x;
    std::cin>>n>>x;
    std::vector<int>weights(n,0);
    // take input the weights
    for(int i =0;i<n;i++){
        std::cin>>weights[i];
    }
    std::cout<<get_minimum_gondolas(weights,x);
    return 0;
}