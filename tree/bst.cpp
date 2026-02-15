// A Binary Search Tree is a special type of binary tree that means it will have at most two chhildren for any root node and the left children values will always be less than the root node and the right childrens will always be greater then the root node.The property of binary search allows us to search for a value in the tree in O(log n) time complexity on average, making it an efficient data structure for searching and sorting operations.

#include<iostream>
#include<algorithm>
#include<vector>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root , int data){
    if(root == nullptr){
        Node* temp = new Node(data);
        return temp;
    }
    if(data > root->data){
        root->right = insert(root->right,data);
    }else{
        root->left = insert(root->left,data);
    }
    return root;
}

Node* build_bst(std::vector<int>&nums){
    Node* root = nullptr;
    for(int i =0;i<nums.size();i++){
        root = insert(root,nums[i]);
    }
    return root;
}

void print_bst(Node * root){
    if(root == nullptr) return;
    std::cout<<root->data<<" ";
    print_bst(root->left);
    print_bst(root->right);
}

int main(){
    std::vector<int>nums = {10,16,8,9,7,6,18,14,20};
    Node* root = build_bst(nums);
    print_bst(root);
    return 0;
}