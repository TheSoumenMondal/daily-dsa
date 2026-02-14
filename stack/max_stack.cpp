#include<iostream>
#include<stack>

class Stack {
    private:
    //current element , max_element
    std::stack<std::pair<int,int>>st;
    public:
    Stack(){}
    void push(int value){
        int top_element = value;
        if(!st.empty()){
            top_element = this->st.top().second;
        }
        this->st.push({value,std::max(top_element , value)});
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int max(){
        return st.top().second;
    }
};

int main(){
    Stack st;
    st.push(100);
    st.push(10000);
    st.push(900);
    st.push(600);
    st.push(200);
    st.push(300);
    std::cout<<st.top()<<std::endl;
    std::cout<<st.max()<<std::endl;
    return 0;
}