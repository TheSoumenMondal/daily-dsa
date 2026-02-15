function bs(arr,low,high,target){
    if(low > high) return -1;
    let mid = Math.floor(low + (high - low) / 2);
    if(arr[mid] == target){
        return mid;
    }else if(target > arr[mid]){
        return bs(arr,mid+1,high , target);
    }
    return bs(arr,low,mid-1,target);
}

function binary_search(arr,target){
    return bs(arr,0,arr.length-1,target);
}

const arr = Array.from(({length : 10}),(_,index) => index+1);
const target = 10;

console.log(binary_search(arr,target));