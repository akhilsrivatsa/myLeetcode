class Solution {
public:
    int l;
   
    bool checkSubstr(string s, unordered_map<string, int> mp, int k){

        int cnt = 0;
        string temp = "";

       // cout << "Here: " << s << endl;

        for(int i = 0; i < s.size(); i++){

            temp = temp + s[i];

            if(temp.size() == k){
                
                mp[temp]--;
                if(mp[temp] >= 0){
                    cnt++;
                }
                if(mp[temp]  <= -1){
                    return false;
                }
                //cout << temp << endl;
                //cout << mp[temp] << endl;
                temp = "";
            }

           
        }

        //cout << "cnt " << cnt << endl;

        return cnt == l;

    }
    vector<int> findSubstring(string s, vector<string>& words) {

        l = words.size();
        int k = words.size() * words[0].size();
        int indCount = words[0].size();
        string temp = "";
        int st = 0, end = k - 1;
        unordered_map<string, int> mp;
        for(string word : words){
            mp[word]++;
        }
        vector<int> res;
        

        while(end < s.length()){

            if(checkSubstr(s.substr(st, end - st + 1), mp, indCount)){
                
                res.push_back(st);
            }
            st++;
            end++;
        }

        return res;
        
    }
};