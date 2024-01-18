class Solution {
public:
    int climbStairs(int n) {
        int ans, prev = 1, curr = 2;
        
        if (n == 1) return prev;
        if (n == 2) return curr;
        
        for (int i = 3; i <= n; i++) {
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        
        return ans;
    }
};
