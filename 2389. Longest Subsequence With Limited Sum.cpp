class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());
        vector<int> ans(queries.size());
        int s = 0;
        for(int i  = 0; i < nums.size(); i++){
            s+=nums[i];
            nums[i] = s;
        }


        for(int i = 0; i < queries.size(); i++){

            int subcount = 0;
            for(int j = 0; j < nums.size(); j++){
                
                if(nums[j] > queries[i]){
                    break;
                }
                subcount++;
            }
            ans[i] = subcount;
        }

        return ans;



        
    }
};