class Solution {
public:

    int dfs(vector<int> &coins, int amount, int index, vector<vector<int>> &dp){

        if(index < 0 || amount < 0) return 0;
        if(amount == 0) return 1;
        if(dp[index][amount] != -1) return dp[index][amount];
        int take = 0;
        if(amount >= coins[index]){
            take = dfs(coins, amount - coins[index], index, dp);
        }

        return dp[index][amount] = take + dfs(coins, amount, index - 1, dp);
    }
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return dfs(coins, amount , coins.size()  -  1, dp);
        
    }
};