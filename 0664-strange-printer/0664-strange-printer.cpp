class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int j = 0; j < N; ++j) {
            for (int i = j; i >= 0; --i) {
                dp[i][j] = i == j ? 1 : (1 + dp[i + 1][j]);
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] != s[i]) continue;
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};