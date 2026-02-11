import java.util.Arrays;
import java.util.Scanner;

public class DistinctNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        long count = 0;
        for (int i = 0; i < n; i++) {
            int elem = sc.nextInt();
            arr[i] = elem;
        }
        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            if (i== 0 || (i!=0 && arr[i] != arr[i - 1])) {
                count++;
            }
        }
        System.out.println(count);
        sc.close();
    }
}
