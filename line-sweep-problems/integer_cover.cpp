#include<iostream>
#include<vector>

bool is_covered(std::vector<std::vector<int>>& ranges, int left, int right) {
    std::vector<int> freq(52,0);
    for(int i =0;i<ranges.size();i++){
        int start = ranges[i][0];
        int end = ranges[i][1];
        freq[start] +=1;
        freq[end+1] -=1;
    }

    for(int i = 1 ;i<52;i++){
        freq[i] += freq[i-1];
    }

    for(int i = left ;i<= right;i++){
        if(freq[i] <= 0){
            return false;
        }
    }

    return true;

}




int main(){
    std::vector<std::vector<int>> ranges = {{15,36},{15,23},{15,44},{30,49},{2,19},{27,36},{7,42},{12,41}};
    int left = 21;
    int right = 21;
    bool ans = is_covered(ranges,left,right);
    std::cout<<ans<<std::endl;
    return 0;
}