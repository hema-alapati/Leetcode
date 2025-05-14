class Solution {
    static final int MOD = 1_000_000_007;
    int[][] dp = new int[26][100_001]; // dp[char][t]

    public int lengthAfterTransformations(String s, int t) {
        int result = 0;
        for (char c : s.toCharArray()) {
            result = (result + dfs(c - 'a', t)) % MOD;
        }
        return result;
    }

    private int dfs(int c, int t) {
        if (t == 0) return 1;
        if (dp[c][t] != 0) return dp[c][t];

        if (c == 25) { // 'z'
            dp[c][t] = (dfs(0, t - 1) + dfs(1, t - 1)) % MOD;
        } else {
            dp[c][t] = dfs(c + 1, t - 1);
        }

        return dp[c][t];
    }
}
