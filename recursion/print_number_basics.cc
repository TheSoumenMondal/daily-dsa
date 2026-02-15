#include<iostream>
#include<vector>

// void print_num_four_more(int n){
//     std::cout<<n+4<<std::endl;
// }

// void print_num_three_more(int n){
//     std::cout<<n+3<<std::endl;
//     print_num_four_more(n);
// }


// void print_num_two_more(int n){
//     std::cout<<n+2<<std::endl;
//     print_num_three_more(n);
// }


// void print_num_one_more(int n){
//     std::cout<<n+1<<std::endl;
//     print_num_two_more(n);
// }

// void print_num(int n){
//     std::cout<<n<<std::endl;
//     print_num_one_more(n);
// }

void print_num(int n){
    if(n>5) return;
    std::cout<<n<<std::endl;
    print_num(n+1);
}

int main(){
    print_num(1);
    return 0;
}