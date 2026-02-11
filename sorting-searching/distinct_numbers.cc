#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i =0;i<n;i++){
        int elem;
        std::cin>>elem;
        arr[i] = elem;
    }
    std::sort(arr.begin() , arr.end());
    int count = 0;
    for(int i =0;i<n;i++){
        if(i == 0 || ( i !=0 && arr[i] != arr[i-1])){
            count++;
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}