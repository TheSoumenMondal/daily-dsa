public class SumofDigits {
    public static int sumOfDigits(int n){
        if(n %10 == n){
            return n;
        }
        return (n%10) + sumOfDigits(n /10);
    }
    public static void main(String[] args) {
        int n = 123;
        System.out.println(sumOfDigits(n));
    }
}
