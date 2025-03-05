class Solution {
    public long coloredCells(int n) {
        long result=1;
        for(int i=1;i<n;i++){
            result=result+4+(4*(i-1));
        }
        return result;
    }
}