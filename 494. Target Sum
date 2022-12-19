class Solution {
public:

    int ways(vector<int> &nums, int target, int sum,int index){

            if(index == nums.size()){
                if(sum == target) return 1;
                return 0;
            }

            return ways(nums, target, sum + nums[index], index + 1) + ways(nums, target, sum - nums[index], index + 1);



    }

    int findTargetSumWays(vector<int>& nums, int target) {


       return ways(nums, target, 0, 0);
        
    }
};