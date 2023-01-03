class Solution {
public:
    bool possible(vector<int> &nums , int m , int mid){
        
        int ps = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(nums[i] > mid || m == 0) return false;
            
            if(ps + nums[i] > mid){
                
                ps = nums[i];
                m--;
            }
            else ps+=nums[i];
        }
        
        if(m==1) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int low = INT_MIN , high = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            
            low = max(low , nums[i]);
            high+=nums[i];
        }
        int result = INT_MAX;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(possible(nums , m , mid)){
                
                result = min(result , mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return result;
    }
};