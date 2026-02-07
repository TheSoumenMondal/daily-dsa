package array;
public class MajorityElementTwo {
    public static int getMajorityElement(int[] nums) {
        int n = nums.length;
        int el = nums[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (cnt == 0)
                el = nums[i];
            if (nums[i] == el)
                cnt++;
            else
                cnt--;
        }
        int total_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el)
                total_cnt++;
        }
        if (total_cnt > (n / 2))
            return el;
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 6, 5, 5 };
        System.out.println(getMajorityElement(arr));
    }
}
