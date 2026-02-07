function max(a, b) {
  return a > b ? a : b;
}

function get_max_points(nums, k) {
  let n = nums.length;
  if (n < k) {
    return -1;
  }
  let left_sum = 0;
  for (let i = 0; i < k; i++) {
    left_sum += nums[i];
  }
  let max_sum = left_sum;
  let right_sum = 0;
  let end = n - 1;
  for (let i = k - 1; i >= 0; i--) {
    right_sum += nums[end--];
    left_sum -= nums[i];
    max_sum = max(max_sum, left_sum + right_sum);
  }
  return max_sum;
}

let arr = [1, 2, 3, 4, 5, 6, 1];

let k = 3;

console.log(get_max_points(arr, k));
