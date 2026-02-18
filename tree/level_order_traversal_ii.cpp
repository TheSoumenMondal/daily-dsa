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

std::vector<std::vector<int>>reverse_level_order_traversal(Node* root){
    if(root == nullptr) return {};
    std::vector<std::vector<int>>traversal;
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        std::vector<int>nums;
        for(int i =0;i<n;i++){
            Node* frontNode = q.front();
            q.pop();
            nums.push_back(frontNode->data);
            if(frontNode->left != nullptr){
                q.push(frontNode->left);
            }
            if(frontNode->right != nullptr){
                q.push(frontNode->right);
            }
        }
        traversal.insert( traversal.begin(),nums);
    }
    return traversal;
}

void print(std::vector<std::vector<int>>&nums){
    for(std::vector<int>num : nums){
        for(int n : num){
            std::cout<<n<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = build(nums,index);
    std::vector<std::vector<int>>traversal = reverse_level_order_traversal(root);
    print(traversal);
    return 0;
}