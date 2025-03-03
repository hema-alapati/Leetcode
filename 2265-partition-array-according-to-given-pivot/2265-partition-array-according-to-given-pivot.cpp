class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int len = nums.size(); // Store the length of the array
        vector<int> res; // Result array
        
        // Step 1: Add elements < pivot
        for(int i = 0; i < len; i++) {
            if(nums[i] < pivot) {
                res.push_back(nums[i]);
            }
        }

        // Step 2: Add elements == pivot
        for(int i = 0; i < len; i++) {
            if(nums[i] == pivot) {
                res.push_back(nums[i]);
            }
        }

        // Step 3: Add elements > pivot
        for(int i = 0; i < len; i++) {
            if(nums[i] > pivot) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};
