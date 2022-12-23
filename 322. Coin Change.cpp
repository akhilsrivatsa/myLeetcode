class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0) return 0;

        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1));
        sort(coins.begin(), coins.end());

        for(int i = 1; i <= amount; i++) dp[0][i] = INT_MAX - 100;

        for(int i = 1; i <= coins.size(); i++){

            for(int j = 1; j <= amount; j++ ){
                

                if(j - coins[i - 1] < 0){
                    dp[i][j] = dp[i - 1][j];
                    continue;

                } 
                 dp[i][j] = min(dp[i - 1][j] , 1 + dp[i][j - coins[i - 1]]);



               
            }
        }


        return dp[coins.size()][amount] > amount ? -1 : dp[coins.size()][amount] ;        
    }
};