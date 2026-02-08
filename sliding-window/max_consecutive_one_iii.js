function get_consecutive_one_count(nums, k) {
    var n = nums.length;
    var max_len = 0;
    var l = 0;
    var r = 0;
    var zero_cnt = 0;
    while (r < n) {
        if (nums[r] == 0) {
            zero_cnt++;
        }
        while (zero_cnt > k) {
            if (nums[l] == 0) {
                zero_cnt--;
            }
            l++;
        }
        max_len = Math.max(max_len, r - l + 1);
        r++;
    }
    return max_len;
}
var arr = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0];
var k = 2;
console.log(get_consecutive_one_count(arr, k));
