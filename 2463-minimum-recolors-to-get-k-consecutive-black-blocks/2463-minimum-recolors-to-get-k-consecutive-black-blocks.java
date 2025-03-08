class Solution {
    public int minimumRecolors(String blocks, int k) {
        int minOperations = Integer.MAX_VALUE;
        int whiteCount = 0;

        // Count initial white blocks in the first window
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                whiteCount++;
            }
        }
        minOperations = whiteCount; // Initialize with the first window's count

        // Slide the window through the string
        for (int i = k; i < blocks.length(); i++) {
            // Remove the leftmost character effect
            if (blocks.charAt(i - k) == 'W') {
                whiteCount--;
            }
            // Add the new rightmost character effect
            if (blocks.charAt(i) == 'W') {
                whiteCount++;
            }

            minOperations = Math.min(minOperations, whiteCount);
        }

        return minOperations;
    }
}
