public class MaximumPointsObtained {
    public static int maxScoreObtained(int[] nums,int k){
        int n = nums.length;
        if(k>n){
            return -1;
        }
        int leftSum = 0;
        for(int i =0;i<k;i++){
            leftSum+=nums[i];
        }
        int maxSum = leftSum;
        int rightSum =0;
        int end = n-1;
        for(int i = k-1;i>=0;i--){
            rightSum+= nums[end--];
            leftSum-=nums[i];
            maxSum = Integer.max(maxSum, rightSum+leftSum);
        }
        return maxSum;
    }
    public static void main(String[] args) {
        int[] arr = {2,2,2};
        int k = 2;
        System.out.println(maxScoreObtained(arr, k));
    }
}
