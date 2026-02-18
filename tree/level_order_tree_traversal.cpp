#include<iostream>
#include<vector>
#include<queue>

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

Node* buildTree(std::vector<int>&nums , int &index){
    if(index >= nums.size()){
        return nullptr;
    }
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

void levelOrderTraversal(Node* root){
    if(root == nullptr) return;
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        std::cout<<node->val<<" ";
        q.pop();
        if(node->left != nullptr){
            q.push(node->left);
        }
        if(node->right != nullptr){
            q.push(node->right);
        }
    }
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = buildTree(nums,index);
    levelOrderTraversal(root);
    return 0;
}