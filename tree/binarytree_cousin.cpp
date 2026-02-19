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

Node* build_tree(std::vector<int>&nums , int &index){
    if(index >= nums.size()){
        return nullptr;
    }
    if(nums[index] == -1){
        index++;
        return nullptr;
    }

    Node* curr = new Node(nums[index]);
    index++;
    curr->left = build_tree(nums,index);
    curr->right = build_tree(nums,index);
    return curr;
}


bool is_parent_same(Node* root ,int x,int y){
    if(root == nullptr){
        return false;
    }
    if(root->left && root->right){
        if(root->left->val == x && root ->right->val == y){
            return false;
        }
        if(root->right->val == x && root->left ->val == y){
            return false;
        }
    }
    return is_parent_same(root->left , x, y) || is_parent_same(root->right , x, y);
}

bool isCousine(Node* root , int node1 , int node2){
    if(root == nullptr){
        return false;
    }
    std::queue<Node*>q;
    q.push(root);
    int level = 0,l1 = -1 , l2 = -1;
    while(!q.empty()){
        int n = q.size();
        for(int i =0;i<n;i++){
            Node* curr_node = q.front();
            q.pop();
            if(curr_node->val == node1){
                l1 = level;
            }
            if(curr_node->val == node2){
                l2 = level;
            }
            if(curr_node->left){
                q.push(curr_node->left);
            }
            if(curr_node->right){
                q.push(curr_node->right);
            }
        }
        if(l1 != -1 || l2 != -1){
            break;
        }
        level++;
    }
    if(l1 != l2){
        return false;
    }
    if(l1 == -1 || l2 == -1){
        return false;
    }
    return is_parent_same(root,node1,node2);
}


int main(){
    std::vector<int>nums = {};
    int index = 0;
    Node* root = build_tree(nums,index);
    std::cout<<isCousine(root,2,3);
    return 0;
}