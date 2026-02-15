// AVL Tree is a self balancing binary search tree.That means the difference of height of left subtree and rightsubtree is not greater than one or less than minus one.And the right nodes are strictly greater than the root nodes and the left ones are strictly lesser.

//But why to use this this gives use the searching , insertion and deletion complexity as O(logn) where the bianry search tree gives the same opetation time complexity as O(n) for the skewed tree.

// But insersion we have to perform some rotation after the insertion as the tree will not be balanced anymore.So after performing the operatino the tree will be balanced again.

#include<iostream>
#include<vector>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left == nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root , int data){
    if(root == nullptr){
        Node* temp = new Node(data);
        return temp;
    }
    // will be implemented
}

void level_order_traversal(Node* root){
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* front_node = q.front();
        std::cout<<front_node->data<<" ";
        q.pop();
        if(front_node->left!= nullptr){
            q.push(front_node->left);
        }
        if(front_node->right){
            q.push(front_node->right);
        }
    }
}

int main(){
    std::vector<int>nums = {12,6,13,40,50,60,13,20,10};
    int n = nums.size();
    Node * root = nullptr;
    for(int i =0;i<n;i++){
        insert(root,nums[i]);
    }
    level_order_traversal(root);
    return 0;
}