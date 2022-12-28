class Solution {
public:

    int dfs(vector<int> &prices, int index , int fee, int hs, vector<vector<int>> &dp){


        if(index == prices.size()){
            return 0;
        }

        if(dp[index][hs] != -1) return dp[index][hs];

        if(!hs){

            int take = dfs(prices, index + 1, fee, !hs, dp) - prices[index];
            int nottake = dfs(prices, index + 1, fee, hs, dp);
            return dp[index][hs] = max(take, nottake);
        }

        int sell = dfs(prices, index + 1, fee, !hs, dp) + prices[index] - fee;
        int notsell = dfs(prices, index + 1, fee, hs, dp);
        return dp[index][hs] = max(sell,notsell); 


            
    }


    int maxProfit(vector<int>& prices, int fee) {


        vector<vector<int>> dp(prices.size(), vector<int> (2 , - 1));
        return dfs(prices, 0 , fee, 0, dp);
        
    }
};