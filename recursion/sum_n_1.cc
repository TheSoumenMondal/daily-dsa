#include<iostream>
#include<vector>

int get_sum(int n){
    if(n == 1){
        return 1;
    }
    return n + get_sum(n-1);
}

int main(){
    int n = 10;
    std::cout<<get_sum(n);
    return 0;
}