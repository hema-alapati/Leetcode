class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<int> primeArray(n+1,1);
        if(n<=2) return 0;
         for (int i = 2; i * i < n; i++) {
            if (primeArray[i]) {
                for (int j = i * i; j < n; j += i) {
                    primeArray[j] = 0; 
                }
            }
        }
        for(int i=2;i<n;i++){
            if(primeArray[i]==1) count++;
        }
        return count;
    }
};