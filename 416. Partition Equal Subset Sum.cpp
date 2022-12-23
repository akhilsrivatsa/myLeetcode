class Solution {
public:

bool dfs(vector<int>& nums, vector<vector<int>> &dp, int index, int sum){

    if(index < 0 || sum < 0) return false;

    if(nums[index] == sum) return true;
    
    if(dp[index][sum] != -1) return dp[index][sum];
    bool take = dfs(nums, dp, index - 1 , sum - nums[index]);
    bool nottake = dfs(nums, dp, index - 1, sum);

    return dp[index][sum] = take || nottake;



}



    bool canPartition(vector<int>& nums) {

        int sum = 0;
       
        for(int num : nums) sum+=num;

        if(sum % 2) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        return dfs(nums, dp, nums.size() - 1, sum / 2);
        
    }
};