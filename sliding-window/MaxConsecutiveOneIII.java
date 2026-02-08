public class MaxConsecutiveOneIII {
    public static int getMaxConsecutiveOneCount(int[] nums,int k){
        int n = nums.length;
        int l =0;
        int r = 0;
        int maxLen = 0;
        int zeroCnt = 0;
        while(r <n){
            if(nums[r] ==0){
                zeroCnt++;
            }
            while(zeroCnt > k){
                if(nums[l] == 0){
                    zeroCnt--;
                }
                l++;
            }
            maxLen = Integer.max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
    public static void main(String[] args) {
        int[] arr = {1,1,1,0,0,0,1,1,1,1,0};
        int k = 2;
        System.out.println(getMaxConsecutiveOneCount(arr, k));
    }
}