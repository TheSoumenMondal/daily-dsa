package array;
public class ArrayRangeSumQuery {

    static class NumArray {
        int[] nums;

        public NumArray(int[] nums) {
            this.nums = nums;
            this.calPrefixSum();
        }

        public void calPrefixSum() {
            for (int i = 1; i < nums.length; i++) {
                nums[i] = nums[i] + nums[i - 1];
            }
        }

        public int sumRange(int left, int right) {
            if (left == 0)
                return nums[right];
            else
                return nums[right] - nums[left - 1];
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9};

        NumArray numarr = new NumArray(arr);

        System.out.println(numarr.sumRange(0, 2));
        System.out.println(numarr.sumRange(1, 3));
        System.out.println(numarr.sumRange(2, 4));
    }
}
