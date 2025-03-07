class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<int> primeArray(n, 1);
        primeArray[0] = primeArray[1] = 0;
        
        for (int i = 2; i * i < n; i++) {
            if (primeArray[i]) {
                for (int j = i * i; j < n; j += i) {
                    primeArray[j] = 0;
                }
            }
        }
        
        return count(primeArray.begin(), primeArray.end(), 1);
    }
};
