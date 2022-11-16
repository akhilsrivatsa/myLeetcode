class Solution {
    public int deleteAndEarn(int[] nums) {
        
        Arrays.sort(nums);
        int max = 0;
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 0);
       
         for(int i = 0; i < nums.length; i++){
            
           for(int j = i - 1; j >= 0; j--){
               
               if(nums[i] == nums[j] + 1){
                   continue;
               }
               
             //  dp[i] = nums[i] + dp[i] + dp[j];
               dp[i] = Math.max(dp[i], dp[j] + nums[i]);
              
             }
            
            if(dp[i] == 0) dp[i] = nums[i];
             max = Math.max(max, dp[i]);
            
        }
        return max;
        
    }
}