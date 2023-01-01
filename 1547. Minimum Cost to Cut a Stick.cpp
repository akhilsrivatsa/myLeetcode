class Solution {
public:
    int dfs(vector<int>& cuts, int l, int r,vector<vector<int>> &cache ){

        if(l > r) return 0;
        if(cache[l][r] != -1) return cache[l][r];

        int mini = 1e7;

        for(int i = 0; i < cuts.size(); i++){

            if(l < cuts[i] && cuts[i] < r){
                int cutCost = r - l + dfs(cuts, l, cuts[i], cache) + dfs(cuts, cuts[i], r,  cache);
                mini = min(mini, cutCost);
            }
        }
        return cache[l][r] = mini == 10e7 ? 0 : mini;

    }
    int minCost(int n, vector<int>& cuts) {

        map<pair<int , int>, int> cache;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

       return dfs(cuts, 0, n, dp);
        
    }
};