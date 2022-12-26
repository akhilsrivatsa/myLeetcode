class Solution {
public:

    int dfs(string &s, string &t, int i, int j, vector<vector<int>> &dp ){


        if(j == t.length()){
            return 1;
        }

        if(i == s.length()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];


        if(s[i] == t[j]){

            return dp[i][j] = dfs(s, t, i + 1, j + 1, dp) + dfs(s, t, i + 1, j, dp);
        }

        return dp[i][j] = dfs(s, t, i + 1, j, dp);
    }
    int numDistinct(string s, string t) {

        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return dfs(s , t, 0, 0, dp);
        
    }
};