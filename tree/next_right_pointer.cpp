#include<iostream>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->next = nullptr;
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

Node* conenct_with_queue(Node* root){
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        Node* mover = nullptr;
        for(int i =0;i<n;i++){
            Node* frontNode = q.front();
            q.pop();

            if(mover != nullptr){
                mover->next = frontNode;
            }
            mover = frontNode;

            if(frontNode->left != nullptr){
                q.push(frontNode->left);
            }
            if(frontNode->right != nullptr){
                q.push(frontNode->right);
            }
        }
        if(mover){
            mover ->next= nullptr;
        }
    }
    return root;
}


Node* connect(Node* root){
    if(root == nullptr){
        return root;
    }
    Node* leftMost = root;
    while(leftMost->left != nullptr){
        Node* curr = leftMost;
        while(curr != nullptr){
            curr->left->next = curr->right;
            if(curr->next){
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }
        leftMost = leftMost->left;
    }
    return root;
}


void print(Node* root){
    Node* temp = root;
    while(temp != nullptr){
        std::cout<<temp->data;
        temp= temp->next;
    }
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = build(nums,index);
    Node* newRoot = conenct_with_queue(root);
    print(newRoot->right->left);
    return 0;
}