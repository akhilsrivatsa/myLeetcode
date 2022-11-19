class Solution {
public:
    
    
    //2.28 AM
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &dp, int rows, int cols, int tar){
        
        
        if(rows < 0 || cols < 0 || cols >= matrix[0].size()) return INT_MAX - pow(10, 4);
        
        if(rows == 0){
            return matrix[rows][cols];
        }
        
        if(dp[rows][cols] != INT_MAX) return dp[rows][cols];
        
        int le =  helper(matrix, dp, rows - 1, cols - 1, matrix[rows][cols] + tar);
        int ri =  helper(matrix, dp, rows - 1, cols + 1, matrix[rows][cols] + tar);
        int down =  helper(matrix, dp, rows - 1, cols, matrix[rows][cols] + tar);
        
        return dp[rows][cols] = min(le, min(ri, down)) + matrix[rows][cols];
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        
        int maxi = INT_MAX;
        
        for(int i = 0; i < matrix[0].size(); i++){
            
            maxi = min(maxi, helper(matrix, dp , matrix.size() - 1, i, matrix[matrix.size() - 1][i]));
        }
        return maxi;
        
    }
};