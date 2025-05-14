class Solution {
    static final int MOD = 1_000_000_007;

    public int lengthAfterTransformations(String s, int t) {
        int[][] dp = new int[26][t + 1];

        // Base case: dp[c][0] = 1 for all characters
        for (int c = 0; c < 26; c++) {
            dp[c][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= t; i++) {
            for (int c = 25; c >= 0; c--) {
                if (c == 25) { // 'z'
                    dp[c][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
                } else {
                    dp[c][i] = dp[c + 1][i - 1];
                }
            }
        }

        // Final result: sum dp[c][t] for each character c in s
        int result = 0;
        for (char ch : s.toCharArray()) {
            result = (result + dp[ch - 'a'][t]) % MOD;
        }

        return result;
    }
}
