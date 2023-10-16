class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>sums;
        int sum=0;
        int maxLen=0;
        sums[0]=-1;

        for(int i=0;i<nums.size();i++){
            nums[i]==0?nums[i]=-1:nums[i]=1;
        }

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            // if(sum==0){
            //     if(maxLen<i+1) maxLen=i+1;
            // }

            if(sums.find(sum)!=sums.end()){
                maxLen=max(maxLen,i-sums[sum]);
            }

            else{
                sums[sum]=i;
            }
        }
        return maxLen;
    }
};