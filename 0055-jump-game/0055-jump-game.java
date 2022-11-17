class Solution {
    public boolean canJump(int[] nums) {
        
        if(nums.length == 1) return true;
        
        int maxLength = nums[0];
        
        
        for(int i = 0; i < nums.length - 1; i++){
            
            if(maxLength == 0 && nums[i] == 0) return false;
            maxLength = Math.max(nums[i], maxLength);
            maxLength--;
        }
        
        return true;
        
    }
}