function get_consecutive_one_count(nums: number[], k: number): number {
  let n = nums.length;
  let max_len: number = 0;
  let l: number = 0;
  let r: number = 0;
  let zero_cnt: number = 0;
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

let arr = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0];
let k = 2;

console.log(get_consecutive_one_count(arr, k));


module.exports = {}