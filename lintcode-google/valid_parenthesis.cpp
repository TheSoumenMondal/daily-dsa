#include<iostream>
#include<string>
#include<stack>

bool check_valid(std::string &str){
    if(str == ""){
        return false;
    }
    std::stack<char>st;
    int n = str.length();
    for(int i =0;i<n;i++){
        if(str[i] == '(' || str[i] == '{'  || str[i] == '[' ){
            st.push(str[i]);
        }else if( (!st.empty()  && str[i] == ')' && st.top() == '(') || ( !st.empty()  && str[i] == ']' && st.top() == '[') || (!st.empty()  && str[i] == '}' && st.top() == '{')){
            st.pop();
        }else{
            return false;
        }
    }
    return st.empty();
}

int main(){
    std::string str = "]";
    std::cout<<std::boolalpha;
    std::cout<<check_valid(str);
    return 0;
}