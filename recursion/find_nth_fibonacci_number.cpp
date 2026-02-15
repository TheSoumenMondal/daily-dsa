#include<iostream>

int fibonacci(int n){
    if(n <2){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<fibonacci(n);
    return 0;
}