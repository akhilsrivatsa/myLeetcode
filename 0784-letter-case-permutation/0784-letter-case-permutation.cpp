class Solution {
public:
    set<string> dict;
    vector<string> ans;

    void helper(string s, int ind){

        if(ind == s.size()){
         
          if(dict.find(s) != dict.end()){
                return;
            }
             cout << s << endl;
            dict.insert(s);
            ans.push_back(s);
            return;
        }
        
        for(int i = ind; i < s.size(); i++){

            char c = s[i];
            helper(s, i + 1);
            if(s[i] >= 'a' && s[i] <= 'z'){
                 s[i] = toupper(c);
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                 s[i] = tolower(c);
            }
            helper(s, i + 1);
            s[i] = c;
        }

    }
    vector<string> letterCasePermutation(string s) {

        //vector<string> ans;
       // ans.push_back(s);
       // dict.insert(s);
        helper(s, 0);
        return ans;
        
    }
};