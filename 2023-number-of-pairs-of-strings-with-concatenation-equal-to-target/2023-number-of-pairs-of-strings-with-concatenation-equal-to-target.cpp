class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {

        unordered_map<int, vector<pair<string, int>>> mp;
        int pairs = 0;
        int tLength = target.size();
       //sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){

            int len = nums[i].length();
            mp[len].push_back(make_pair(nums[i], i));
        }

        for(int i = 0; i < nums.size(); i++){
            int l1 = nums[i].length();
            int remLen = tLength - l1;
            
            for(int j = 0; j < mp[remLen].size(); j++){

                pair<string, int> p = mp[remLen][j];
                if(p.second == i){
                    continue;
                }
                if(p.first + nums[i] == target){
                    pairs++;
                }
            }
            
        }

        return pairs;
        
    }
};