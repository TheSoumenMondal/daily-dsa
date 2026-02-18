#include<iostream>

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

int get_next_successor(Node* root , int target){
    if(root == nullptr){
        return -1;
    }
    std::queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode->left != nullptr){
            q.push(frontNode->left);
        }
        if(frontNode->right != nullptr){
            q.push(frontNode->right);
        }

        if(frontNode->data == target){
            if(q.empty()){
                return -1;
            }else{
                return q.front()->data;
            }
        }
    }
    return -1;
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = buildTree(nums,index);
    int target = 3;
    std::cout<<get_next_successor(root,target);
    return 0;
}