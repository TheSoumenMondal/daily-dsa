public class CountDominentIndices {
    public static int dominantIndices(int[] nums) {
        int n = nums.length;
        int[] suffixArray = new int[n];
        suffixArray[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            suffixArray[i] = nums[i + 1] + suffixArray[i + 1];
        }
        int cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            suffixArray[i] = suffixArray[i] / (n - i - 1);
            if (nums[i] > suffixArray[i]) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        int[] nums = { 5, 3, 2, 4, 1 };
        System.out.println(dominantIndices(nums));
    }
}
