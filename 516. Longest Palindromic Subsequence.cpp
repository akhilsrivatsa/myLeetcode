class Solution {
public:

    int dfs(string &s1, string &s2, int i, int j,  vector<vector<int>> &dp){

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + dfs(s1, s2, i - 1, j -1, dp);
        }

        return dp[i][j] = max(dfs(s1, s2, i, j - 1, dp), dfs(s1, s2, i - 1, j, dp));



    }
    int longestPalindromeSubseq(string s) {

        string s2 = s;
        reverse(s2.begin(), s2.end());
       vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));

       return dfs(s, s2, s.length() - 1, s.length() - 1, dp);
        

        
    }
};