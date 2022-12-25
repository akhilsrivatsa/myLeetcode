class Solution {
public:


    int maxSeq(string &text1, string &text2, int i, int j, vector<vector<int>> &dp ){

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] !=  -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + maxSeq(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(maxSeq(text1, text2, i - 1, j, dp), maxSeq(text1, text2, i, j - 1, dp));

        


    }
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));


        return maxSeq(text1, text2, text1.length() - 1, text2.length() - 1, dp);
        
    }
};