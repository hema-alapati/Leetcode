class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        int count = n;  // Initialize count to n
        for (int i = 0; i < N; i++) {
            if (flowerbed[i] == 0) {
                bool prev = (i == 0) || flowerbed[i - 1] == 0;
                bool next = (i == N - 1) || flowerbed[i + 1] == 0;
                if (prev && next) {
                    flowerbed[i] = 1;
                    count--;
                }
                if (count == 0) return true;  // No need to check for count >= n
            }
        }
        return count <= 0;  // Instead of checking count >= n, check if it's less than or equal to 0
    }
};
