#include<iostream>

class Node{
    public:
    int data;
    Node* left_node;
    Node* right_node;
    Node(int data){
        this->data = data;
        left_node = nullptr;
        right_node = nullptr;
    }
};

static int idx = -1;

Node* buildTree(std::vector<int>&nums){
    idx++;
    if(nums[idx] == -1){
        return nullptr;
    }
    Node *root = new Node(nums[idx]);
    root->left_node = buildTree(nums);
    root->right_node = buildTree(nums);
    return root;
}

void preorder_traversal(Node* root){
    if(root== nullptr){
        return;
    }
    std::cout<<root->data<<" ";
    preorder_traversal(root->left_node);
    preorder_traversal(root->right_node);
}

int main(){
    std::vector<int>preorder_sequence = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder_sequence);
    preorder_traversal(root);
    return 0;
}