class Solution {
public:
int dfs(string &s1, string &s2, int i, int j,  vector<vector<int>> &dp){

        
        if(i < 0 && j < 0) return 0;
        
        if(i < 0) return j + 1;

        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];


        if(s1[i] == s2[j]){
            return dp[i][j] = dfs(s1, s2, i - 1,j - 1, dp);
        }


        return dp[i][j] = 1 + min(dfs(s1, s2, i, j - 1, dp), dfs(s1, s2, i - 1, j, dp));

    }
    int minDistance(string word1, string word2) {



        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(), - 1));
        
        
        return dfs(word1, word2, word1.length() - 1, word2.length() - 1, dp);
        
    }
};