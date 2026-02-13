#include<iostream>
#include<vector>

bool lemonade_change(std::vector<int>&bills){
    int five_cnt = 0;
    int ten_cnt = 0;
    for(int i =0;i<bills.size();i++){
        if(bills[i] == 20){
            if(five_cnt >=1 && ten_cnt >=1){
                ten_cnt -=1;
                five_cnt-=1;
            }else if(five_cnt >=3){
                five_cnt-=3;
            }else{
                return false;
            }
        }else if(bills[i] == 10){
            ten_cnt++;
            if(five_cnt >=1){
                five_cnt--;
            }else{
                return false;
            }
        }else{
            five_cnt++;
        }
    }
    return true;
}

int main(){
    std::vector<int> bills = {5,5,5,5,20,20,5,5,20,5};
    std::cout<<lemonade_change(bills);
    return 0;
}