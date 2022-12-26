class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<int>> mp;
        vector<vector<string>> ans;

        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }


        for(auto it = mp.begin(); it != mp.end(); it++){

            vector<string> temp;
            cout << it->first<<endl;
            for(int i = 0; i < it->second.size(); i++){
                temp.push_back(strs[it->second[i]]);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};