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

std::vector<int>bottom_view(Node* root){

    std::vector<int>nums ;
    if(root == nullptr){
        return nums;
    }

    std::map<int,Node*>mpp;
    std::queue<std::pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        std::pair<Node*,int> frontNode = q.front();
        q.pop();
        mpp[frontNode.second] = frontNode.first;
        if(frontNode.first->left != nullptr){
            q.push({frontNode.first->left,frontNode.second -1});
        }
        if(frontNode.first->right != nullptr){
            q.push({frontNode.first->right,frontNode.second +1});
        }
    }

    for(std::pair<int , Node*> mp : mpp){
        nums.push_back(mp.second->data);
    }

    return nums;

}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = build(nums,index);
    std::vector<int>ans = bottom_view(root);
    for(auto it : ans){
        std::cout<<it<<" ";
    }
    return 0;
}