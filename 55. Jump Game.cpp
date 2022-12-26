class Solution {
public:
    bool canJump(vector<int>& nums) {


        int maxLength = -1;


        for(int i = 0; i < nums.size(); i++){


            if(i == nums.size() - 1) return true;

            maxLength = max(maxLength, nums[i]);

            if(maxLength <= 0) return false;
            maxLength--;

        }

        return false;
        
    }
};