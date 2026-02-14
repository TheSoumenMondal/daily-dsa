#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxRobbery(const vector<int>& nums, const vector<int>& colors) {
    int n = (int)nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    // dp[i] = max money we can rob from houses 0..i
    // We use space optimization: only track last 2 values
    long long prev2 = 0;           // dp[i-2]
    long long prev1 = nums[0];     // dp[i-1]
    
    for (int i = 1; i < n; ++i) {
        long long curr;
        if (colors[i] == colors[i-1]) {
            // Same color as previous: cannot rob both i and i-1
            // Either skip i or take i (which means we must have skipped i-1)
            curr = max(prev1, prev2 + nums[i]);
        } else {
            // Different color: we can rob both i and i-1
            // Best is always to take current house
            curr = prev1 + nums[i];
        }
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// Example local main (for testing)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read n then nums and colors (adjust to problem input format)
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    cout << maxRobbery(nums, colors) << '\n';
    return 0;
}
