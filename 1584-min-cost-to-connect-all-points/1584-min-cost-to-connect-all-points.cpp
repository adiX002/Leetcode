class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int N = A.size(), ans = 0, cur = 0;
        vector<int> dist(N, INT_MAX), seen(N);
        for (int i = 0; i < N - 1; ++i) {
            int x = A[cur][0], y = A[cur][1];
            seen[cur] = 1;
            for (int j = 0; j < N; ++j) {
                if (seen[j]) continue;
                dist[j] = min(dist[j], abs(A[j][0] - x) + abs(A[j][1] - y));
            }
            cur = min_element(begin(dist), end(dist)) - begin(dist);
            ans += dist[cur];
            dist[cur] = INT_MAX;
        }
        return ans;
    }
};