class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; ){
            int maintain_cost = cost[i];
            int j;
            for(j = i+1; j < n && s[j] == s[i]; ++j){
                maintain_cost = max(maintain_cost, cost[j]);
            }
            
            if(j-i > 1){
                ans += accumulate(cost.begin()+i, cost.begin()+j, 0) - maintain_cost;
            }
            
            i = j;
        }
        
        return ans;
    }
};