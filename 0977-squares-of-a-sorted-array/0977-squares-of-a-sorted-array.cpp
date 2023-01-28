class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> res(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int ind = nums.size() - 1;

        while(left <= right){

            if(abs(nums[left]) < nums[right]){
                res[ind--] = nums[right] * nums[right];
                right--;
            }else{
                res[ind--] = nums[left] * nums[left];
                left++;
            }
        }
        return res;
        
    }
};