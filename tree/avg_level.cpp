#include<iostream>
#include<vector>

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
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

std::vector<float> averageLevels(Node* root){
    std::vector<float> averages;
    if(root == nullptr){
        return averages;
    }
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        int sum =0;
        for(int i =0;i<size;i++){
            Node* node = q.front();
            q.pop();
            sum+=node->data;
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        float avg = (float) sum / (float)size;
        averages.push_back(avg);
    }
    return averages;
}

void print_arr(std::vector<float>&nums){
    for(float num : nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int>nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = buildTree(nums,index);
    std::vector<float>averages = averageLevels(root);
    print_arr(averages);
    return 0;
}


// 1,2,-1,-1,3,4,-1,-1,5,-1,-1

            // 1
    // 2                3
                // 4           5
// -1.    -1.  -1.   -1    -1.    -1