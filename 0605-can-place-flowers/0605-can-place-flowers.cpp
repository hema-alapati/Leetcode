class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        int count = 0;
        if (n == 0) return true;
        for (int i = 0; i < N; i++) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    count++;
                }
                if (count >= n) return true;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
