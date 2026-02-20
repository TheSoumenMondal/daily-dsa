function remove_duplicate(nums : number[]){
    let n:number = nums.length;
    let unique_index = 0;
    for(let i =0;i<n;i++){
        if(nums[i] != nums[unique_index]){
            let temp = nums[i];
            nums[i] = nums[unique_index + 1];
            nums[unique_index+1] = temp;
            unique_index++;
        }
    }
    return unique_index + 1;
}

const nums : number[] = [0,0,1,1,1,2,2,2,2,3,4,5];
console.log(remove_duplicate(nums))

export default {
    remove_duplicate
}