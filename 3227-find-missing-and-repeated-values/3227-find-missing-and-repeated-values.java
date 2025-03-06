class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int missing = -1, repeating = -1;
        int n = grid.length;
        int size = n * n;
        int[] freq = new int[size + 1];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                freq[grid[i][j]]++;
            }
        }

        for (int i = 1; i <= size; i++) {
            if (freq[i] == 2) {
                repeating = i;
            }
            if (freq[i] == 0) {
                missing = i;
            }
        }
        
        return new int[]{repeating, missing};
    }
}
