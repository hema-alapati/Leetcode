class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        unordered_set<char> seen;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (seen.count(c) == 1) {
                seen.clear();
                seen.insert(c);
                count++;
            } else {
                seen.insert(c);
            }
        }

        return count + 1; //adding the last substring
    }
};