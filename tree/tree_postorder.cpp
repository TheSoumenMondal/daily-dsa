#include<iostream>

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->left = nullptr;
        this->right = nullptr;
        this->val = val;
    }
};

Node* buildTree(std::vector<int>&nums , int &index){
    if(index >= nums.size()) return nullptr;
    if(nums[index] == -1){
        index++;
        return nullptr;
    }
    Node* newNode = new Node(nums[index]);
    index++;
    newNode->left = buildTree(nums,index);
    newNode->right = buildTree(nums,index);
    return newNode;
}

void postOrder(Node* root){
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->val<<" ";
}
int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = buildTree(nums,index);
    postOrder(root);
    return 0;
}