class Solution {
public:
    int dfs(vector<int> &nums, int st, int end, vector<vector<int>> &dp){

        if(st > end){
            return 0;
        }

        if(dp[st][end] != -1) return dp[st][end];
        int maxPoints = 0;

        for(int i = st ; i <= end; i++){

            int points = nums[i] * nums[st - 1] * nums[end + 1] +  dfs(nums , st , i - 1, dp) + dfs(nums, i + 1, end, dp);
            maxPoints = max(maxPoints, points);
        }
        return dp[st][end] = maxPoints;

       
    }
    int maxCoins(vector<int>& nums) {
       
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
       return dfs(nums, 1 , n, dp);
        
    }
};