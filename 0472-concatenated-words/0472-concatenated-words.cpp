class Solution {
public:
    static bool comp(string &s1, string &s2){

        return s1.length() < s2.length();
    }
    bool canBesplit(string s, set<string> &dict, vector<bool> &dp, map<string, int> &mp){
        
        if(s == "") return true;

        bool ans = false;

        for(int i = 0; i <  s.size(); i++){

            if(dict.find(s.substr(0, i + 1)) != dict.end()){

               if(canBesplit(s.substr(i + 1), dict, dp, mp)){
                   mp[s.substr(i + 1)] = 1;
                    return true;
                }
            }
            
        }

        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        set<string> dict;
        map<string, int> mp; 
        vector<string> ans;
        sort(words.begin(), words.end(), comp);

        for(int i = 0; i < words.size(); i++){
            vector<bool> dp (words[i].size());

            if(canBesplit(words[i], dict, dp, mp)){
                ans.push_back(words[i]);
            }
            dict.insert(words[i]);

        }

        return ans;

        
    }
};