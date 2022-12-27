class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {


        vector<int> gd(capacity.size());
        int ans = 0;

        for(int i = 0; i < capacity.size(); i++){

            gd[i] = capacity[i] - rocks[i];
        }

        sort(gd.begin(), gd.end());

        for(int diff : gd){

            if(diff == 0){
                ans++;
                continue;
            }
            additionalRocks = additionalRocks - diff;
            if(additionalRocks < 0) break;
            ans++;
        }
        return ans;
        
    }
};