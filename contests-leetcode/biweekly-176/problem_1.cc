#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string word : words){
            int total = 0;
            for(char ch : word){
                total+=weights[ch - 'a'];
            }
            int rem = total % 26;
            char mapped_char = 'z' - rem;
            res+= mapped_char;
        }
        return res;
}

int main(){
    vector<string> words = {"a","b","c"};
    vector<int> weights = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    string result = mapWordWeights(words, weights);
    cout << result << endl;
    return 0;
}