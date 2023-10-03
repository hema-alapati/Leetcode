class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // support variables
        int res = 0, seen[101] = {};
        for (auto n: nums) {
            // for each occurrence, we had the previously found matches to res...
            res += seen[n];
            // ...and then we update seen 
            seen[n]++;
        }
        return res;
    }
};