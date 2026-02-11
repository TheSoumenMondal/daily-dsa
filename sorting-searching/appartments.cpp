#include<iostream>
#include<vector>
#include<algorithm>


int main(){
    int n , m , k;
    std::cin>>n>>m>>k;
    //desired appartment sizes
    std::vector<int> desired_appartment_size(n,0);
    for(int i =0;i<n;i++){
        std::cin>>desired_appartment_size[i];
    }
    //size of the each appartment
    std::vector<int>appartment_size(m,0);
    for(int i =0;i<m;i++){
        std::cin>>appartment_size[i];
    }

    int total_ditributions = 0;

    std::sort(desired_appartment_size.begin() , desired_appartment_size.end());
    std::sort(appartment_size.begin(),appartment_size.end());

    int f_ptr = 0;
    int s_ptr = 0;

    while(f_ptr < n && s_ptr < m){
        if(appartment_size[s_ptr] < desired_appartment_size[f_ptr] - k ){
            s_ptr++;
        }else if(appartment_size[s_ptr] > desired_appartment_size[f_ptr] + k){
            f_ptr++;
        }else{
            total_ditributions++;
            f_ptr++;
            s_ptr++;
        }
    }

    std::cout<<total_ditributions;

    return 0;
}
