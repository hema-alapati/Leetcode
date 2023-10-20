class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        unordered_set<char> seen;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (seen.find(c) != seen.end()) {
                seen.clear();
                count++;
            }
            seen.insert(c);
        }

        // The remaining characters in the last partition should also be counted.
        if (!seen.empty()) {
            count++;
        }

        return count;
    }
};