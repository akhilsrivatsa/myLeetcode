class Solution {
public:

    int dfs(vector<int> &nums , int index , int target, vector<vector<int>>&dp){

        if(target < 0 || index == nums.size()) return 0;

        if(dp[index][target] != -1) return dp[index][target];

        if(target == 0){
            return 1;
        }
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){

            if(target - nums[i] < 0) break;
            ans = ans + dfs(nums, i, target - nums[i], dp);
        }

        return dp[index][target] = ans;

        
    }
    int combinationSum4(vector<int>& nums, int target) { 

        sort(nums.begin(), nums.end());
        vector<vector<int>> dp (nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, 0, target, dp);
        
    }
};