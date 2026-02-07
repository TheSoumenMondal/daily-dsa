const union_array = (arr , brr) => {
    let i =0;
    let j =0;
    let n = arr.length;
    let m = brr.length;
    let union_arr = [];
    while(i<n && j<m){
        if(arr[i] < brr[j]){
            if(union_arr.length == 0 || union_arr[union_arr.length - 1] != arr[i]){
                union_arr.push(arr[i]);
            }
            i++;
        }else if(brr[j] < arr[i]){
            if(union_arr.length == 0 || union_arr[union_arr.length - 1] != brr[j]){
                union_arr.push(brr[j]);
            }
            j++;
        }else{
            if(union_arr.length ==0 || union_arr[union_arr.length - 1] != arr[i]){
                union_arr.push(arr[i]);
            }
            i++;
        }
    }

    while(i<n){
        if(union_arr.length ==0 || union_arr[union_arr.length -1] != arr[i]){
            union_arr.push(arr[i]);
        }
        i++;
    }

    while(j<m){
        if(union_arr.length ==0 || union_arr[union_arr.length -1] != brr[j]){
            union_arr.push(brr[j]);
        }
        j++;
    }
    return union_arr;
}


const arr = [1,2,3,4,4,5,5,5,6,7];
const brr = [1,2,3,9,9,10,11,11,11,11,11];

const result = union_array(arr,brr);
console.log(result)