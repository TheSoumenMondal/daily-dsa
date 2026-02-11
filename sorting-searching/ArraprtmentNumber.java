import java.util.Arrays;
import java.util.Scanner;

public class ArraprtmentNumber {
    public static int getMaxAllocatedAppartment(int desiredAppartmentSize[] , int actulaAppartmentSize[], int k){
        int totalAllocatedAppartments = 0;
        int i =0;
        int j = 0;
        int n = desiredAppartmentSize.length;
        int m = actulaAppartmentSize.length;
        Arrays.sort(desiredAppartmentSize);
        Arrays.sort(actulaAppartmentSize);
        while(i<n && j <m){
            if(actulaAppartmentSize[j] < desiredAppartmentSize[i] - k){
                j++;
            }else if(actulaAppartmentSize[j] > desiredAppartmentSize[i] + k){
                i++;
            }else{
                totalAllocatedAppartments++;
                i++;
                j++;
            }
        }
        return totalAllocatedAppartments;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[] desiredAppartmentSize = new int[n];
        for(int i = 0; i < n; i++){
            desiredAppartmentSize[i] = sc.nextInt();
        }
        int[] appartmentSize = new int[m];
        for(int i = 0; i < m; i++){
            appartmentSize[i] = sc.nextInt();
        }
        System.out.println(getMaxAllocatedAppartment(desiredAppartmentSize, appartmentSize, k));
        sc.close();
    }
}
