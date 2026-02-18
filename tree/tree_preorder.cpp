#include<iostream>

class TreeNode {
    public:
    int val ;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* buildTree(std::vector<int>&nums , int &index){
    if(index>= nums.size()) return nullptr;

    if(nums[index] == -1){
        index++;
        return nullptr;
    }
    TreeNode* newNode = new TreeNode(nums[index]);
    index++;
    newNode->left = buildTree(nums,index);
    newNode->right = buildTree(nums,index);
    return newNode;
}

void preOrderTraversal(TreeNode* root){
    if(root == nullptr) return;
    std::cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    TreeNode* root = buildTree(nums,index);
    preOrderTraversal(root);
    return 0;
}