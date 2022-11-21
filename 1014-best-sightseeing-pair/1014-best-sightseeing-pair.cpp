class Solution {
public:
    
    //2.52 AM
    int maxScoreSightseeingPair(vector<int>& nums) {
        
        
        int st = nums[0];
        int mxP = 0;
        
        for(int i = 1; i < nums.size(); i++){
            
            mxP = max(mxP, st + (nums[i] - i));
            st = max(st, nums[i] + i);
        }
        return mxP;
        
    }
};