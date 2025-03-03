class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int count=0;
        int index=0;
        int[] ans=new int[nums.length];

        for(int num:nums){
            if(num==pivot) count++;
            else if(num<pivot) {
                ans[index]=num;
                index++;
            }
        }

        while(count>0){
            ans[index]=pivot;
            index++;
            count--;
        }

        for(int num:nums){
            if(num>pivot){
                ans[index]=num;
                index++;
            }
        }

        return ans;
    }
}