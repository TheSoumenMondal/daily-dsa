function second_largest(arr){
    let largest = -1;
    let second_largest = -1;
    for(let i =0;i<arr.length;i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] > second_largest && arr[i] < largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}


let arr = [5,2,7,9,12,4,8,0];

console.log(second_largest(arr));