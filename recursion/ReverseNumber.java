public class ReverseNumber {
    public static int digitsCount(int n){
        if(n == 0) return 1;
        return 1 + (int)Math.floor(Math.log10(n));
    }
    public static int reverseNumber(int n){
        if(n % 10 == n) return n;
        return (n % 10) * (int)Math.pow(10, digitsCount(n) - 1) + reverseNumber(n / 10);
    }
    public static void main(String[] args) {
        int n = 1234;
        System.out.println(reverseNumber(n));
    }
}
