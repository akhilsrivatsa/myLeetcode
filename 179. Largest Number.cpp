class Solution {
public:
    static bool comp(int &a1, int &a2){
        string s1 = to_string(a1);
        string s2 =  to_string(a2);

        return s2 + s1 < s1 + s2;
    }
    string largestNumber(vector<int>& nums) {


        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        int i = 0;
        bool leading = true;
        for(int i = 0; i < nums.size(); i++){

            if(leading && nums[i] == 0 && i != nums.size() - 1){
                continue;
            }
            leading = false;
            ans = ans + to_string(nums[i]);
        }


        return ans;
        
    }
};