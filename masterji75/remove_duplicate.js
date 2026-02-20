function remove_duplicate(nums) {
    var n = nums.length;
    var unique_index = 0;
    for (var i = 0; i < n; i++) {
        if (nums[i] != nums[unique_index]) {
            var temp = nums[i];
            nums[i] = nums[unique_index + 1];
            nums[unique_index + 1] = temp;
            unique_index++;
        }
    }
    return unique_index + 1;
}
var nums = [0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5];
console.log(remove_duplicate(nums));
