#include<iostream>

int digits_sum(int n){
    if(n == 0) return 0;
    int rem = n % 10;
    return rem + digits_sum(n/10);
}

int main(){
    int n = 1199;
    std::cout<<digits_sum(n);
    return 0;
}