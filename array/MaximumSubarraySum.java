package array;
import java.util.ArrayList;

public class MaximumSubarraySum {
    public static int getMaximumSubArraySum(ArrayList<Integer> arr){
        int maxSum = Integer.MIN_VALUE;
        int sum = 0;
        for(int val : arr) {
            sum+=val;
            maxSum = Integer.max(maxSum, sum);
            if(sum < 0) sum =0;
        }
        return maxSum;
    }
    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<>();
        array.add(-2);
        array.add(1);
        array.add(-3);
        array.add(4);
        array.add(-1);
        array.add(2);
        array.add(1);
        array.add(-5);
        array.add(4);
        System.out.println(getMaximumSubArraySum(array));
    }
}
