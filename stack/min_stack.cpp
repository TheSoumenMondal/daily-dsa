#include<iostream>
#include<stack>

class Stack {
    private:
    //current element , min_element
    std::stack<std::pair<int,int>>st;
    public:
    Stack(){}
    void push(int value){
        int top_element = value;
        if(!st.empty()){
            top_element = this->st.top().second;
        }
        this->st.push({value,std::min(top_element , value)});
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int min(){
        return st.top().second;
    }
};

int main(){
    Stack st;
    st.push(100);
    st.push(200);
    st.push(300);
    std::cout<<st.top()<<std::endl;
    std::cout<<st.min()<<std::endl;
    return 0;
}