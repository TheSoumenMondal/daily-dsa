import java.util.ArrayList;

public class LongestSubstring {
    public static int getLongestSubstring(String str){
        int maxLen = 0;
        int r =0;
        int l = 0;
        int n = str.length();
        ArrayList<Integer> vis = new ArrayList<>();
        for(int i =0;i<256;i++){
            vis.add(-1);
        }
        while (r<n) {
            if(vis.get(str.charAt(r))!= -1 && vis.get(str.charAt(r)) >= l){
                l = vis.get(str.charAt(r)) + 1;
            }
            maxLen = Integer.max(maxLen, r - l + 1);
            vis.set(str.charAt(r), r);
            r++;
        }
        return maxLen;
    }
    public static void main(String[] args) {
        String str = "abcabcbb";
        System.out.println(getLongestSubstring(str));
    }
}
