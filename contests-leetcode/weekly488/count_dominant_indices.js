var dominantIndices = function(nums) {
    let len = nums.length;
    let helper_array = new Array(len).fill(0);
    //calculating the suffix sum array
    for(let i = len-2;i>=0;i--){
        helper_array[i] = helper_array[i+1] + nums[i+1];
    }
    //calulating the average : floor means rounding to lower value like : 3.5 to 3
    for(let i = len - 2; i>=0;i--){
        helper_array[i] = Math.floor(helper_array[i]/(len - i - 1));
    }
    let cnt = 0;

    for(let i =0;i<len-1;i++){
        if(nums[i] > helper_array[i]){
            cnt++;
        }
    }
    return cnt;
};


const arr = [5, 3, 2, 4, 1];
console.log(dominantIndices(arr));