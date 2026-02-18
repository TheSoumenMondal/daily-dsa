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

std::vector<int>left_view(Node* root){
    if(root == nullptr){
        return {};
    }
    std::vector<int>ans;
    std::queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        bool isFirst = true;
        for(int i =0;i<size;i++){
            Node* frontNode = q.front();
            if(isFirst){
                ans.push_back(frontNode->data);
                isFirst = false;
            }
            q.pop();
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }

    return ans;
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = build(nums,index);
    std::vector<int>ans = left_view(root);
    for(auto it : ans){
        std::cout<<it<<" ";
    }
    return 0;
}