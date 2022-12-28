class Solution {
public:
    bool dfs(string &s, string &p, int i, int j, vector<bool> &check,  vector<vector<int>> &dp){

        if(i < 0){

            if(j < 0) return true;

            return !check[j];

        } 
         if(j < 0) return false;

        if( dp[i][j] != -1) return dp[i][j];

       

        if(s[i] == p[j] || p[j] == '?'){
            return   dp[i][j] =  dfs(s, p, i - 1, j - 1, check, dp);
        }

        if(p[j] == '*'){
            return  dp[i][j] = dfs(s, p, i - 1, j - 1, check, dp) || dfs(s, p, i - 1, j, check, dp) || dfs(s, p, i, j - 1, check, dp);
        }


        return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {

       

        vector<bool> check(p.size());
        bool found = false;

        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));

        for(int i = 0; i < p.size(); i++){

            if(p[i] >= 'a' && p[i] <= 'z' || p[i] == '?'){
                found =  true;
            }
            check[i] = found;
        }
       
        return dfs(s, p, s.size() - 1, p.size() - 1, check, dp);
    }
};