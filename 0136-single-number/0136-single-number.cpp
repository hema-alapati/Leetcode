class Solution {
public:
// the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};