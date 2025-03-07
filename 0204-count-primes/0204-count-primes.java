class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0;
        int count=0;
        boolean[] primeArray = new boolean[n];
        
        for(int i=2;i<n;i++){
            primeArray[i]=true;
        }
        for(int i=2;i*i<=n;i++){
            if(primeArray[i]){
                for(int j=i*i;j<n;j+=i){
                    primeArray[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(primeArray[i]) count++;
        }
        return count;
    }
}