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

std::vector<std::vector<int>> zigzagTraversal(Node* root){
    if(root == nullptr){
        return {};
    }
    std::vector<std::vector<int>>traversal;
    std::stack<Node*>st1,st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty()){
        std::vector<int>level;
        if(!st1.empty()){
            while(!st1.empty()){
                Node* top_element = st1.top();
                st1.pop();
                level.push_back(top_element->data);
                if(top_element->left != nullptr){
                    st2.push(top_element->left);
                }
                if(top_element->right != nullptr){
                    st2.push(top_element->right);
                }
            }
        }else{
            while(!st2.empty()){
                Node* top_element = st2.top();
                st2.pop();
                level.push_back(top_element->data);
                if(top_element->right != nullptr){
                    st1.push(top_element->right);
                }
                if(top_element->left != nullptr){
                    st1.push(top_element->left);
                }
            }
        }

        traversal.push_back(level);

    }

    return traversal;
}

void print_zigzagTraversal(std::vector<std::vector<int>>&nums){
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
    Node* root = buildTree(nums,index);
    std::vector<std::vector<int>>traversal = zigzagTraversal(root);
    print_zigzagTraversal(traversal);
    return 0;
}