class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int prev){

        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }

        if(prev >= matrix[i][j]){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];


        int up = dfs(matrix, dp, i - 1, j, matrix[i][j]) + 1;
        int down = dfs(matrix, dp, i + 1, j, matrix[i][j]) + 1;
        int left = dfs(matrix, dp, i, j - 1, matrix[i][j]) + 1;
        int right = dfs(matrix, dp, i, j + 1, matrix[i][j]) + 1;

        return dp[i][j] = max(up, max(down, max(right, left)));


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));

       for(int i = 0; i < matrix.size(); i++){
           for(int j = 0; j < matrix[0].size(); j++){

               if(dp[i][j] == -1){
                   dfs(matrix, dp, i, j, -1);
               }

           }
       }

       int max_value = INT_MIN;
       for(int i = 0; i < dp.size(); i++){
           for(int j = 0; j < dp[0].size(); j++){

               max_value = max(max_value, dp[i][j]);
           }
       }

       return max_value;


        
    }
};