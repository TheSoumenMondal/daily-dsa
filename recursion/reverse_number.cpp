#include<iostream>

int digits_cnt(int n){
    if(n==0)return 0;
    return 1 + floor(log10(n));
}

int reverse_number(int n){
    if(n%10 == n) return n;
    return (n%10) * pow(10,digits_cnt(n)-1) + reverse_number(n/10);
}

int main(){
    int n = 1;
    // std::cout<<digits_cnt(n);
    std::cout<<reverse_number(n);
    return 0;
}