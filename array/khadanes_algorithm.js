function max_subarray_sum(nums) {
  let max_sum = -Infinity;
  let sum = 0;
  for (let num of nums) {
    sum = sum + num;
    if (sum > max_sum) {
      max_sum = sum;
    }
    if (sum < 0) sum = 0;
  }
  return max_sum;
}

function main() {
  let arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
  console.log(max_subarray_sum(arr));
}

main();
