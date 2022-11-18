class Solution {
public:
    int jump(vector<int>& nums) {
        
       if(nums.size() <= 1) return 0;
        int dp[nums.size()];
        fill_n (dp, nums.size(), INT_MAX - 1);

        for(int i = nums.size() - 1; i>=0; i--){
            
            if(i == nums.size() - 1 || nums[i] == 0){
               dp[i] = INT_MAX - 1;
               continue;
            }
            
            if(i + nums[i] >= nums.size() - 1 ){
                dp[i] = 1;
                continue;
            }
            for(int j = i + 1; j <= i + nums[i]; j++){
                
              
                dp[i] = min(dp[i], dp[j] + 1);
           }
            
            cout<<dp[i]<<endl;
          
            
            
            
        }
        return dp[0];
        
    }
};