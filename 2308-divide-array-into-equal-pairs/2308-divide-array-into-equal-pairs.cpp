class Solution {
public:
    bool divideArray(std::vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check if all numbers appear an even number of times
        for (const auto& pair : freq) {
            if (pair.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};