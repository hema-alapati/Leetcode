class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            maxSum=max(maxSum,temp);
            temp=max(temp,0);
        }
        return maxSum;
    }
};