class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount=0,k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroCount++;
            }
            else{
                nums[k++]=nums[i];
            }
        }
        while(zeroCount!=0){
            nums[k++]=0;
            zeroCount--;
        }
    }
};