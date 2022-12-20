class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {


        set<string> dict;
        map<string, int> mp;
        for(int i = 0; i < wordDict.size(); i++){

            dict.insert(wordDict[i]);
        }
        queue<string> q;
        q.push(s);
        while(!q.empty()){

            string temp = q.front();
            q.pop();
            for(int i = 0; i < temp.length() ; i++){
                string inter =  temp.substr(0, i + 1);
                auto it = dict.find(inter);
                if(it != dict.end()){

                    string rem = temp.substr(i + 1, temp.length() - i + 1);
                    if(mp[rem]) continue;


                    mp[rem] = 1;
                    if(rem == "") return true;
                    q.push(rem);

                }   


            }






        }

        return false;
        
    }
};