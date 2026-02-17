#include<iostream>
#include<vector>

//total ways to reach destination
int helper(int n , int r ,int c){
    if(r == n || c==n){
        return 1;
    }
    return helper(n, r+1 , c) + helper(n , r, c+1);
    
}


int count_ways(int n){
    return helper(n,1,1);
}

int main(){
    int n = 3;
    std::cout<<count_ways(n);
    return 0;
}