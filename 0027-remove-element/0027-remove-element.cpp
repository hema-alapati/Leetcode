class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(auto it:nums){
            if(it!=val){
                nums[k++]=it;
            }
        }
        return k;
    }
};