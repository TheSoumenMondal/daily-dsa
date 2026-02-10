public class SecondLargest {
    public static int getSecondLargest(int[] arr){
        int n = arr.length;
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        for(int i =0;i<n;i++){
            if(arr[i] > largest ){
                secondLargest = largest;
                largest = arr[i];
            }else if(arr[i] > secondLargest && arr[i] < largest){
                secondLargest = arr[i];
            }

        }
        return secondLargest;
    }
    public static void main(String[] args) {
        int arr[] = {5,2,7,9,4,12,8,0};
        System.out.println(getSecondLargest(arr));
    }
}
