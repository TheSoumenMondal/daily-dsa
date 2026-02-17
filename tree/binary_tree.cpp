#include<iostream>

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(){
    int data;
    std::cin>>data;
    if(data == -1){
        return nullptr;
    }
    Node* curr = new Node(data);
    curr->left = buildTree();
    curr->right = buildTree();
    return curr;
}

int main(){
    Node* root;
    root = buildTree();
    return 0;
}