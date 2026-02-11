import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Collections;

public class MergeAdjacentDuplicate {
    public static List<Long> mergeAdjacent(int[] nums) {
        List<Long> list = new ArrayList<>();
        Stack<Long> st = new Stack<>();
        st.push((long)nums[0]);
        long n = nums.length;

        for(long i = 1; i < n; i++){
            long top = st.peek();
            if(top == nums[(int)i]){
                st.pop();
                long element = nums[(int)i] * 2L;
                while(!st.empty() && element == st.peek()){
                    st.pop();
                    element *= 2;
                }
                st.push(element);
            } else {
                st.push((long)nums[(int)i]);
            }
        }

        while(!st.empty()){
            long el = st.pop();
            list.add(el);
        }

        Collections.reverse(list);
        return list;
    }
    
    public static void main(String[] args) {
        int[] test1 = {2,1,1,2};
        System.out.println(mergeAdjacent(test1));
        
        int[] test2 = {2, 2, 4};
        System.out.println(mergeAdjacent(test2));

        int[] test3 = {3,7,5};
        System.out.println(mergeAdjacent(test3));
    }
}
