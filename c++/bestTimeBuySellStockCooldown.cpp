// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/*
dp[len][2]
Case 1: We have a stock on day i, max of the below
- I bought it today
    dp[i-2][0] - prices[i]
- Carrying it forward
    dp[i-1][1]

Case 2: We have no stock on day i, max of the below
- I sold it today
    dp[i-1][1] + prices[i]
- Carrying it forward, doing nothing
    dp[i-1][0]
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        
        if (len <= 1) return 0;
        
        if (len == 2)
            if (prices[0] < prices[1])
                return prices[1] - prices[0];
            else
                return 0;
        
        int dp[len][2];
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);
        
        for(int i = 2; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[len-1][0];
    }
};