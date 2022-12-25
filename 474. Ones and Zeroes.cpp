class Solution {
public:
    int dfs(vector<string> &strs, vector<pair<int, int>> &weight, int m, int n, int zeroes, int ones, int index,
     vector<vector<vector<int>>> &dp){

        if(index < 0) return 0;

        int take = 0;
        pair<int, int>  p = weight[index];

        if(dp[index][zeroes][ones] != -1) return dp[index][zeroes][ones];

        if(p.first + zeroes <= m && p.second + ones <= n){
            take = dfs(strs, weight, m, n, zeroes + p.first, ones + p.second, index - 1, dp) + 1;
        }

        int nottake = dfs(strs, weight, m, n, zeroes, ones, index - 1, dp);

        return dp[index][zeroes][ones] =  max(take, nottake);


    }


    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int, int>> weights(strs.size());
        for(int i = 0; i < strs.size(); i++){

            int ones = 0;
            int zeroes = 0;

            for(char ch : strs[i]){
               
               ch == '0' ? zeroes++ : ones++;
            }

           weights[i] = make_pair(zeroes, ones);
            
        }
         vector<vector<vector<int>>> dp(strs.size(),  vector<vector<int>>(m + 1, vector<int>( n +1, -1)));
      return  dfs(strs, weights, m, n, 0, 0, strs.size() - 1, dp);
        
    }
};