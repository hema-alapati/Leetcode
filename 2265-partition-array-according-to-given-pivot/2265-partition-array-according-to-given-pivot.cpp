class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int len = nums.size();
        vector<int> ans(len);
        int count = 0, index = 0;
        for(int i = 0; i < len; i++) {
            if(nums[i] < pivot) ans[index++] = nums[i];
            else if(nums[i] == pivot) count++;
        }
        while(count--) ans[index++] = pivot;
        for(int i = 0; i < len; i++) {
            if(nums[i] > pivot) ans[index++] = nums[i];
        }
        return ans;
    }
};
