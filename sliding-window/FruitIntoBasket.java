import java.util.HashMap;

public class FruitIntoBasket {
    public static int totalFruit(int[] fruits) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int n = fruits.length;
        HashMap<Integer, Integer> mpp = new HashMap<>();
        while (r < n) {
            mpp.put(fruits[r], mpp.getOrDefault(fruits[r], 0) + 1);
            while (mpp.size() > 2) {
                mpp.put(fruits[l], mpp.getOrDefault(fruits[l], 0) - 1);
                if (mpp.getOrDefault(fruits[l], 0) == 0) {
                    mpp.remove(fruits[l]);
                }
                l++;
            }
            maxLen = Integer.max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }

    public static void main(String[] args) {
        int fruits[] = {1,2,3,2,2};
        System.out.println(totalFruit(fruits));
    }
}
