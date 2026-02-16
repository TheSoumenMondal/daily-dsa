public class CheckSortedArray {
    
    static boolean helper(int[] nums , int startIndex){
        if(startIndex >= nums.length-1){
            return true;
        }
        if(nums[startIndex] > nums[startIndex +1]){
            return false;
        }
        return helper(nums, startIndex + 1);
    }

    static boolean isArraySorted(int[] nums){
        return helper(nums, 0);
    }

    public static void main(String[] args) {
        int[] nums = {10,20,30,40,50,60};
        System.out.println(isArraySorted(nums));
    }
}
