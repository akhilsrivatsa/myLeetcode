class Solution {
public:
    bool dfs(string &s1, string &s2, string &s3, int i, int j, int k,  vector<vector<int>> &dp){

       

        if(i >= s1.length() && j >= s2.length() && k >= s3.length()){

            return true;
        }
        if(i >= s1.length() && j >= s2.length()){
            return false;
        }

        if(s1[i] != s3[k] && s2[j] != s3[k]){
           
            return false;
        }

         if(i >= s1.length()){

             if(s2[j] == s3[k]){
                 return dfs(s1, s2, s3, i, j + 1, k + 1, dp);
             }
             return false;
        }

        if(j >= s2.length()){

             if(s1[i] == s3[k]){
                 return dfs(s1, s2, s3, i + 1, j, k + 1, dp);
             }
             return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool first = false;
        bool second = false;

        if(s1[i] == s3[k]){
            first =  dfs(s1, s2, s3, i + 1, j, k + 1, dp);
        }

        if(s2[j] == s3[k]){
            second = dfs(s1, s2, s3, i, j + 1, k + 1, dp);
        }
        
       return dp[i][j] = first || second;
        
    }
    bool isInterleave(string s1, string s2, string s3) {

        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));

        return dfs(s1, s2, s3, 0, 0, 0, dp);
        
    }
};