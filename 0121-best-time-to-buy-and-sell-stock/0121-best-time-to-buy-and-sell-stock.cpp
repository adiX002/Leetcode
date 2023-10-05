class Solution {
public:
    void solve(vector<int> &prices, int i, int &mini, int &maxi)
    {
        // Base Case
        if (i == prices.size())
        {
            return;
        }

        if (prices[i] < mini)
        {
            mini = prices[i];
        }

        int todaysProfit = (prices[i] - mini);

        if (todaysProfit > maxi)
        {
            maxi = todaysProfit;
        }

        solve(prices, (i + 1), mini, maxi);
    }
    
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = INT_MIN;
        
        solve(prices, 0, minPrice, maxProfit);
        
        return maxProfit;
//         int minPrice = prices[0], maxProfit = 0;

//         for (int i = 1; i < prices.size(); i++) {
//             maxProfit = max(maxProfit, (prices[i] - minPrice));
//             minPrice = min(prices[i], minPrice);
//         }

//         return maxProfit;
    }
};
