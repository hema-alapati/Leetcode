class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n=colors.length;
        int left=0; int result=0;

        for(int i=1;i<n+(k-1);i++){
            if(colors[i%n]==colors[(i-1)%n]){
                left=i;
            }
            if(i-left+1>k){
                left+=1;
            }
            if(i-left+1==k){
                result+=1;
            }
        }
        return result;
        //referred: https://www.youtube.com/watch?v=Zexx16dNPX8
    }
}