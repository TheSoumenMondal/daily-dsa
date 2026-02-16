public class LinearSearch {
    public static int helper(int[] nums ,int curr , int target){
        if(curr == nums.length) return -1;
        if(nums[curr] == target){
            return curr;
        }
        return helper(nums, curr+1 , target);
    }
    public static int linearSearch(int[] nums , int target){
        return helper(nums, 0, target);
    }
    public static void main(String[] args) {
        int [] nums = {10,20,50,30,40,60,100};
        int target = 50;
        System.out.println(linearSearch(nums, target));
    }
}
