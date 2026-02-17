#include<iostream>
#include<vector>
#include<climits>


void build_seg_tree(int index , int low , int high , std::vector<int>&nums , std::vector<int>&seg){
    if(low == high){
        seg[index] = nums[low];
        return;
    }
    int mid = (low + high) / 2;
    build_seg_tree(2*index + 1 , low , mid , nums , seg);
    build_seg_tree(2*index + 2 , mid + 1 , high , nums ,seg);
    seg[index] = std::min(seg[2*index + 1] , seg[2*index + 2]);
}

int query(int index ,int low , int high , std::vector<int>&seg , int l , int r){
    if(high < l || low > r){
        return INT_MAX;
    }else if(low >= l && high <= r){
        return seg[index];
    }else{
        int mid = (low + high) / 2;
        int left = query(2*index +1 , low , mid , seg , l , r);
        int right = query(2*index +2 , mid + 1 , high , seg , l , r);
        return std::min(left , right);
    }
}

void update(int index , int low , int high , std::vector<int>&nums ,  std::vector<int>&seg , int ind , int value){
    if(low == high){
        nums[ind] = value;
        seg[index] = value;
        return;
    }
    int mid = (low + high) /2;
    if(ind <= mid) { 
        update(2*index + 1 , low , mid ,nums, seg , ind , value);
    }else{
        update(2*index + 2 , mid + 1 , high , nums,seg , ind , value);
    }
    seg[index] = std::min(seg[2*index +1 ], seg[2*index + 2]);
}

int main(){
    int l,r;
    std::cin>>l>>r;
    std::vector<int>nums = {1,2,3,2,2,34,99,4,6};
    int n = nums.size();
    std::vector<int>seg(4*n,0);
    build_seg_tree(0,0,n-1,nums,seg);
    std::cout<<seg[0]<<std::endl;
    std::cout<<query(0,0,n-1,seg , l,r)<<std::endl;
    return 0;
}