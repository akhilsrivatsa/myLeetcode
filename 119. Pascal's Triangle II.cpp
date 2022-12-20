class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1));

        for(int i = 0; i < dp.size(); i++){
            dp[i].resize(i + 1);
        }

        dp[0][0] = 1;

        for(int i = 1; i < dp.size() ; i++){

            for(int j = 0; j < dp[i].size() ; j++){

                if(j == 0 || j == dp[i].size() - 1){
                    dp[i][j] = 1;
                    continue;
                } 


                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];


            }

        }

        return dp[rowIndex];






    }
};