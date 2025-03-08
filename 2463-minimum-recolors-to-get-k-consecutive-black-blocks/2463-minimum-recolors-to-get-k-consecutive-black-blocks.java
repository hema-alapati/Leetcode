class Solution {
    public int minimumRecolors(String blocks, int k) {
        int minOps=Integer.MAX_VALUE;
        int count=0;

        for(int i=0;i<k;i++){
            if(blocks.charAt(i)=='W'){
                count++;
            }
        }
        minOps=count;

        for(int i=k;i<blocks.length();i++){
            if(blocks.charAt(i-k)=='W') count--;
            if(blocks.charAt(i)=='W') count++;
            minOps=Math.min(minOps,count);
        }
        return minOps;
    }
}