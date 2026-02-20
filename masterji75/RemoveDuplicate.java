class RemoveDuplicate {
    public static int removeDuplicate(int[] nums){
        int n = nums.length;
        int uniqueu_index = 0;
        for(int i =0;i<n;i++){
            if(nums[i] != nums[uniqueu_index]){
                int temp = nums[i];
                nums[i] = nums[uniqueu_index +1];
                nums[uniqueu_index + 1] = temp;
                uniqueu_index++;
            }
        }
        return uniqueu_index + 1;
    }
    public static void main(String[] args){
        int[] nums = {0,0,1,1,1,2,2,3,3,4};
        System.out.println(removeDuplicate(nums));
    }
}