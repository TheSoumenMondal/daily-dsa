#include<iostream>
#include<vector>
#include<map>
#include<queue>

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


Node* build(std::vector<int>&nums , int &index){
    if(index >= nums.size()){
        return nullptr;
    }
    if(nums[index] == -1){
        index++;
        return nullptr;
    }
    Node* newNode = new Node(nums[index]);
    index++;
    newNode->left = build(nums,index);
    newNode->right = build(nums,index);
    return newNode;
}

std::vector<int>right_view(Node* root){
    std::vector<int>ans;
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        int last = q.front()->data;
        for(int i =0;i<size;i++){
            Node* frontNode = q.front();
            last = frontNode->data;
            q.pop();
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        ans.push_back(last);
    }
    return ans;
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = build(nums,index);
    std::vector<int>ans = right_view(root);
    for(auto it : ans){
        std::cout<<it<<" ";
    }
    return 0;
}