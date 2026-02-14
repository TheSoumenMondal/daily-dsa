#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int prefixConnected(vector<string>& words, int k) {
        unordered_map<string ,int>mpp;
        for(string word : words){
            if(word.size() >= k){
                string prefix = word.substr(0,k);
                mpp[prefix]++;
            }
        }
        int g = 0;
        for(auto it : mpp){
            if(it.second >= 2){
                g++;
            }
        }
        return g;
}

int main(){
    vector<string> words = {"dfzohkbzaejelxcmcyriybcsrmwdcnhognzfyquifrijmblmmenyhesayngbsuoz","dfmrjsuyhtfqylzefltctcfnmybelrdzfbmidargenvdesw","daercqodnwckrlvpxjixdutxjpsdehwcagkeo","ihzjtlbipqqwncongzanbydzibjpoykboljcdfjbifoedeldqaiqfpcitihnz","iqqxrtxcsopfpjzwrmcoutgsjgfqnke","ippqsqbiznyevtvgzstqrahlpsmttqxzahbglxnbyf","imifhuyrdcjqnyhbvtswtijwcmxtaacrazhklwgepiuqxfklpgrxophgpqfvtweriitkobm","iscbvfyeomecqcltzsuwhyyazhcmmixlwnonff","iylvqeymcxnhyvjvesvklhgeawlhnelgruewzweafteapdlpsrhlteecxuqwflpvrgr","rtersufrkdemlvrsubgnfdimexhzykwrtomgtxtnvdlbq","stkohkmrgnrtvqyqvxoapqcudfsutvgujxhobxzsswdnkiulpsfejznysqydmuxwtwwuyioewgpzbibvmxndcyqvdszjwkaqsryt","jpkxjyebhhzwkfsgrukidojcvvwihqupjpeopndexsdtbfcihlprhmh","lqpjmugidnzebgdti","gitzvglwiqdtonkzkkjwhpkqzebxxklo","kdvudkwfkzzecet","s"};
    int k = 1;
    int result = prefixConnected(words, k);
    cout << result << endl;
}