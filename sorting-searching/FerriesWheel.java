import java.util.Arrays;

public class FerriesWheel {
    public static int getMaximumGondolas(int[] weights , int maxWeight){
        int n = weights.length;
        int leftPtr =0;
        int rightPtr = n-1;
        int count = 0;
        Arrays.sort(weights);
        while(leftPtr <= rightPtr){
            if(weights[leftPtr] + weights[rightPtr] <= maxWeight){
                leftPtr++;
                rightPtr--;
            }else{
                rightPtr--;
            }
            count++;
        }
        return count;
    }
    public static void main(String[] args) {
        int maxWeight = 100;
        int[] weights = {90,20,80,30,70,40,60,50,10,100};
        System.out.println(getMaximumGondolas(weights, maxWeight));
    }
}
