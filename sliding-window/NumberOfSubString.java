public class NumberOfSubString {
    public static int numberOfSubstrings(String s) {
        int n = s.length();
        int left = 0;
        int[] cnt = new int[3];
        int ans = 0;

        for (int right = 0; right < n; right++) {
            char c = s.charAt(right);
            if (c >= 'a' && c <= 'c') cnt[c - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += n - right;
                char lc = s.charAt(left++);
                if (lc >= 'a' && lc <= 'c') cnt[lc - 'a']--;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(numberOfSubstrings("abcabc"));
    }
}
