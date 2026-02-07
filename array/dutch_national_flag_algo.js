function dutch_nationa_flag_algo(nums){
    let n = nums.length;
    let low =0;
    let mid =0;
    let high = n-1;
    while(mid<=high){
        if(nums[mid] ==1){
            mid++;
        }else if(nums[mid] == 0){
            let temp = nums[mid];
            nums[mid] = nums[low];
            nums[low] = temp;
            low++;
            mid++;
        }else{
            let temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}


let arr = [1,1,2,2,0];
dutch_nationa_flag_algo(arr);
console.log(arr)