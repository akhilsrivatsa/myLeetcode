class Solution {
public:


    int helper(int m, int n, int maxMove, int startRow, int startCol, vector<vector<vector<int>>> &dp ){

        if((startRow < 0 || startCol < 0 || startRow >= m || startCol >= n) && maxMove >= 0){
            return 1;
        }

        if(maxMove < 0){
            return 0;
        }

        if(dp[startRow][startCol][maxMove] != -1) return dp[startRow][startCol][maxMove];


        return dp[startRow][startCol][maxMove] =  
                 ((helper(m, n, maxMove - 1, startRow + 1, startCol, dp) % 1000000007 + 
                 helper(m, n, maxMove - 1, startRow - 1, startCol, dp) % 1000000007) % 1000000007  +
                (helper(m, n, maxMove - 1, startRow, startCol + 1, dp) % 1000000007+
                helper(m, n, maxMove - 1, startRow, startCol - 1, dp) % 1000000007) % 1000000007);

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

       vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int>(maxMove + 1, -1)));
        return helper(m, n, maxMove, startRow, startColumn, dp) % 1000000007;
        
    }
};