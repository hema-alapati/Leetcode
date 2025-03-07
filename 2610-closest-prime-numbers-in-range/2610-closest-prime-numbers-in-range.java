class Solution {
    public int[] closestPrimes(int left, int right) {
        if (right < 2) return new int[]{-1, -1};
        boolean[] primeArray = new boolean[right+1];
        ArrayList<Integer> primes = new ArrayList<>();
        
        for(int i=2;i<=right;i++){
            primeArray[i]=true;
        }
        for(int i=2;i*i<=right;i++){
            if(primeArray[i]){
                for(int j=i*i;j<=right;j+=i){
                    primeArray[j]=false;
                }
            }
        }
        for(int i=left;i<=right;i++){
            if(primeArray[i]){
                primes.add(i);
            }
        }
        
        if(primes.size()<2){
            return new int[] {-1,-1};
        }

        int min_gap=Integer.MAX_VALUE;
        int[] result = new int[2];
        for(int i=1;i<primes.size();i++){
            int gap=primes.get(i)-primes.get(i-1);
            if(gap<min_gap){
                min_gap=gap;
                result[0]=primes.get(i-1);
                result[1]=primes.get(i);
            }
        }
        return result;
    }
}