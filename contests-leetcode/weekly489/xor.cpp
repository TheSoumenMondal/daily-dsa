#include<iostream>
#include<vector>
#include<deque>
using namespace std;

const int BITS = 15;

struct TrieNode {
    int children[2];
    int cnt;
    TrieNode() : cnt(0) { children[0] = children[1] = -1; }
};

vector<TrieNode> trie;

int newNode(){
    trie.push_back(TrieNode());
    return trie.size() - 1;
}

void insert(int num){
    int cur = 0;
    for(int i = BITS; i >= 0; i--){
        int bit = (num >> i) & 1;
        if(trie[cur].children[bit] == -1){
            trie[cur].children[bit] = newNode();
        }
        cur = trie[cur].children[bit];
        trie[cur].cnt++;
    }
}

void remove(int num){
    int cur = 0;
    for(int i = BITS; i >= 0; i--){
        int bit = (num >> i) & 1;
        cur = trie[cur].children[bit];
        trie[cur].cnt--;
    }
}

int queryMax(int num){
    int cur = 0;
    int res = 0;
    for(int i = BITS; i >= 0; i--){
        int bit = (num >> i) & 1;
        int want = 1 - bit;
        if(trie[cur].children[want] != -1 && trie[trie[cur].children[want]].cnt > 0){
            res |= (1 << i);
            cur = trie[cur].children[want];
        } else if(trie[cur].children[bit] != -1 && trie[trie[cur].children[bit]].cnt > 0){
            cur = trie[cur].children[bit];
        } else {
            return res;
        }
    }
    return res;
}

int maxXor(vector<int>&nums, int k){
    int n = nums.size();
    
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] ^ nums[i];
    }
    
    trie.clear();
    newNode();
    
    deque<int> maxQ, minQ;
    int left = 0;
    int ans = 0;
    
    insert(prefix[0]);
    
    for(int right = 0; right < n; right++){
        while(!maxQ.empty() && nums[maxQ.back()] <= nums[right]) maxQ.pop_back();
        maxQ.push_back(right);
        
        while(!minQ.empty() && nums[minQ.back()] >= nums[right]) minQ.pop_back();
        minQ.push_back(right);
        
        while(!maxQ.empty() && !minQ.empty() && nums[maxQ.front()] - nums[minQ.front()] > k){
            remove(prefix[left]);
            left++;
            if(!maxQ.empty() && maxQ.front() < left) maxQ.pop_front();
            if(!minQ.empty() && minQ.front() < left) minQ.pop_front();
        }
        
        int xorVal = queryMax(prefix[right + 1]);
        ans = max(ans, xorVal);
        
        insert(prefix[right + 1]);
    }
    
    return ans;
}

int main(){
    vector<int> nums1 = {5, 4, 5, 6};
    cout << maxXor(nums1, 2) << endl; // 7

    vector<int> nums2 = {5, 4, 5, 6};
    cout << maxXor(nums2, 1) << endl; // 6

    vector<int> nums3 = {7};
    cout << maxXor(nums3, 0) << endl; // 7

    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << maxXor(nums4, 0) << endl; // 5

    vector<int> nums5 = {0, 0, 0};
    cout << maxXor(nums5, 0) << endl; // 0

    vector<int> nums6 = {3, 1, 2};
    cout << maxXor(nums6, 1) << endl; // 3 (subarray [1,2] -> XOR=3, or [3] -> 3)

    return 0;
}