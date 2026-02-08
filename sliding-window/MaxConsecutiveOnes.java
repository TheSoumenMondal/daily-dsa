public class MaxConsecutiveOnes {
    public static int getConsutiveOnes(int[] nums){
        int n = nums.length;
        int leftPtr = 0;
        int rightPtr = 0;
        int maxLen =0;
        int prevZeroPosition = 0;
        int zeroCnt = 0;
        while(rightPtr < n){
            if(nums[rightPtr] == 0){
                if(zeroCnt == 1){
                    leftPtr = prevZeroPosition + 1;
                }
                prevZeroPosition = rightPtr;
                zeroCnt++;
            }

            maxLen = Integer.max(maxLen, rightPtr - leftPtr + 1);
            rightPtr++;
        }
        return maxLen;
    }
    public static void main(String[] args) {
        int[] nums = {1,0,1,1,0};
        System.out.println(getConsutiveOnes(nums));
    }
}
