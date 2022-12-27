class Solution {
public:

 int dfs(vector<int> &prices , int index ,int k, int hs, vector<vector<vector<int>>> &dp){
        if(k <= 0 || index == prices.size()) return 0;
        

        if(dp[index][k][hs] != -1) return dp[index][k][hs];
        if(!hs){

            int buy = dfs(prices, index + 1, k, !hs, dp) - prices[index];
            int notBuy = dfs(prices, index + 1, k, hs, dp);

            return dp[index][k][hs] = max(buy, notBuy);
        }

        int sell = dfs(prices, index  + 1, k - 1,  !hs, dp) + prices[index];
        int notsell = dfs(prices, index + 1, k, hs, dp);

        return dp[index][k][hs] =max(sell , notsell);





    }

    int maxProfit(int k, vector<int>& prices) {

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (k + 1, vector<int> (2, -1)));

        return dfs(prices, 0,  k, 0, dp);
        
    }
};