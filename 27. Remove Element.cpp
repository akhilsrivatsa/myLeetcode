class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

         int la = nums.size() - 1;
        int i = 0;

        while(i <= la){

            if(nums[i] != val){
                i++;
            }else{

                swap(nums[i], nums[la]);
                la--;

            }

        }

        return i;
        
    }
};