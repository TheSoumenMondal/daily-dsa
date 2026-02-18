#include<iostream>
#include<vector>

class Node {
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


Node* build_tree_from_arr(std::vector<int>&nums , int &ind){
    ind++;
    if(ind>=nums.size()|| nums[ind] == -1 ){
        return nullptr;
    }
    Node* new_node = new Node(nums[ind]);
    new_node->left = build_tree_from_arr(nums,ind);
    new_node->right = build_tree_from_arr(nums,ind);
    return new_node;
}

void in_order(Node* root){
    if(root== nullptr){
        return;
    }
    in_order(root->left);
    std::cout<<root->val<<" ";
    in_order(root->right);
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int ind = -1;
    Node* root = build_tree_from_arr(nums,ind);
    in_order(root);
    return 0;
}