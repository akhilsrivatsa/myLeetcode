class Solution {
public:
    int dfs(map<int, vector<pair<int, int>>>&mp, int src, int dst, int k, vector<vector<int>> &dp){

       if(src == dst) return 0;

       int minprice = INT_MAX - 10e3;

       if( k < 0) return minprice;

        if(dp[src][k] != -1) return dp[src][k];
        
        for(int i = 0; i < mp[src].size(); i++){

            minprice = min(minprice, dfs(mp, mp[src][i].first, dst, k - 1, dp) + mp[src][i].second);
        }
        
        return dp[src][k] = minprice;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        vector<vector<int>> dp(n , vector<int> (k + 1, -1));

        map<int, vector<pair<int, int>>> mp;
        for(int i = 0; i < flights.size(); i++){
            mp[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }

        int res = dfs(mp, src, dst, k, dp);


        return res == INT_MAX - 10e3 ? -1 : res;
        
    }
};