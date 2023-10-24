class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority;
        int n=nums.size();
        // if(n==1) return nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                majority=nums[i];
                count++;
            }
            else if(nums[i]==majority){
                count++;
            }
            else{
                count--;
            }
        }
        return majority;
    }
};