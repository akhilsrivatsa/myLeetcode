class Solution {
public:
    int dfs(vector<int> &prices, vector<vector<int>> &dp, int i, int hs){

        if(i >= prices.size()){
            return 0;
        }

        if(dp[hs][i]) return dp[hs][i];

        if(!hs){
            int buy = dfs(prices, dp, i + 1, 1) - prices[i];
            int notbuy = dfs(prices, dp, i + 1, hs);
            return dp[hs][i] =  max(buy, notbuy);
        }

        int sell = dfs(prices, dp, i + 2, 0) + prices[i];
        int notsell = dfs(prices, dp, i + 1, hs);
        return dp[hs][i] = max(sell, notsell);
    }


    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()));
        return dfs(prices, dp , 0 , 0);
        
    }
};