class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool isInc=true;
        bool isDec=true;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) isInc=false;
        }
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) isDec=false;
        }
        return isInc||isDec;
    }
};