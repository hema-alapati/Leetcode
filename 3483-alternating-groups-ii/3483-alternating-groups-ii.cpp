class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int left = 0, result = 0;

        for (int i = 1; i < n + (k - 1); i++) {
            if (colors[i % n] == colors[(i - 1) % n]) {
                left = i;
            }
            if (i - left + 1 >= k) {
                result++;
            }
        }
        
        return result;
    }
};
