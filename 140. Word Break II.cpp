class Solution {
public:
    void dfs(string s, set<string> &dict, vector<string> &ans, string str, set<pair<string, string>> &vis){


        //if(vis.find(make_pair(s, str)) != vis.end()){
          //  return;
        //}

        vis.insert(make_pair(s, str));

        if(s == ""){
            ans.push_back(str.substr(0, str.length() - 1));
            return;
        }


        for(int i = 0; i < s.length(); i++){

            string temp = s.substr(0, i + 1);
            if(dict.find(temp) != dict.end()){
                dfs(s.substr(i + 1), dict, ans, str + temp + " ", vis);
            }
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<string> ans;
        set<string> dict;
        set<pair<string, string>> vis;
        for(string str : wordDict){
            dict.insert(str);
        } 

         dfs(s, dict, ans, "", vis);
        return ans;
        
    }
};