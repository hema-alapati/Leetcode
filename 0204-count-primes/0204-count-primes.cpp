class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> primeArray(n, true);
        primeArray[0] = primeArray[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (primeArray[i]) {
                for (int j = i * i; j < n; j += i) {
                    primeArray[j] = false;
                }
            }
        }

        return count(primeArray.begin(), primeArray.end(), true);
    }
};
