class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> m;
        vector<int> vec = nums;
        int n = nums.size();

        sort(vec.begin(), vec.end());
        // Put the values in hash-map according to their values corresponding to their places in nums 
        for(int i=n-1;i>=0;i--) {
            m[vec[i]] = i;
        }
        // Saving the result again in nums for returning
        for(int i=0; i<n; i++) {
            nums[i] = m[nums[i]];
        }
        return nums;
    }
};