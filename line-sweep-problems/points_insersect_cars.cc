#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

//TC : O(n * k) where k is max differce of start and end of a car position.
int number_of_points(std::vector<std::vector<int>> &cars){
    std::set<int>st;
    for(int i =0;i<cars.size();i++){
        int start = cars[i][0];
        int end = cars[i][1];
        for(int j = start ; j<=end;j++){
            st.insert(j);
        }
    }
    return st.size();
}

int number_of_points_better(std::vector<std::vector<int>> &cars){
    int n = cars.size();
    std::vector<int> freq(122,0);

    // set the first starting as 1 and the end + 1 as -1
    for(int i =0;i<n;i++){
        freq[cars[i][0]] += 1;
        freq[cars[i][1] + 1] -=1;
    }

    // prefix sum : now the -1 makes sence and make that 0 so the points which are not includes in our ans are ignored.

    int count = 0;
    int running = 0;

    for(int i =1;i<freq.size();i++){
        running +=freq[i-1];
        if(running > 0){
            count++;
        }
    }

    return count;

}

int main(){
    std::vector<std::vector<int>>cars = {{3,6},{1,5},{4,7}};
    std::cout<<number_of_points_better(cars);
    return 0;
}