public class BinarySearch {
    public static int binarySearch(int[] nums ,int  target ,int low ,int high){
        if(low > high) return -1;
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]){
            return binarySearch(nums, target, mid+1, high);
        }
        return binarySearch(nums, target, low, mid-1);
    }
    public static void main(String[] args) {
        int[] num = {1,2,3,4,5,6,7,9};
        int target = 100;
        int low = 0;
        int high = num.length - 1;
        System.out.println(binarySearch(num, target, low, high));
    }
}
