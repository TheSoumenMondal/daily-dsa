#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class SegTree {
public:
    std::vector<int> seg;

    SegTree(int size) {
        seg.resize(4 * size);
    }

    void build_tree(int index, int left, int right, std::vector<int>& nums) {
        if (left == right) {
            seg[index] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        build_tree(2 * index + 1, left, mid, nums);
        build_tree(2 * index + 2, mid + 1, right, nums);

        seg[index] = std::min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int l, int r, int low, int high, int index) {
        // No overlap
        if (r < low || l > high)
            return INT_MAX;

        // Complete overlap
        if (l <= low && high <= r)
            return seg[index];

        // Partial overlap
        int mid = (low + high) / 2;

        int left_val = query(l, r, low, mid, 2 * index + 1);
        int right_val = query(l, r, mid + 1, high, 2 * index + 2);

        return std::min(left_val, right_val);
    }
};

int main() {
    std::vector<int> nums = {10, 20, 30, 40, 11, 22, 33, 44, 15, 5};

    SegTree st(nums.size());
    st.build_tree(0, 0, nums.size() - 1, nums);

    std::cout << st.query(0, 5, 0, nums.size() - 1, 0);

    return 0;
}
