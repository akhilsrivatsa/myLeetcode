class Solution {
 // 2.58
    public:
    int maxSubArray(vector<int>& nums) {
        
        
        int cs = 0;
        int mxs = INT_MIN;
        
        for(int i = 0;i < nums.size(); i++){
            
            
            cs+= nums[i];
            
            mxs = max(mxs, cs);
            
            if(cs <=0 ) cs= 0;
        }
        return mxs;
        
    }
};