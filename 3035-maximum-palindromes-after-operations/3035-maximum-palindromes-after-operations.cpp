class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        
        vector<int> cnt(26, 0);
        int pairs = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j <words[i].size(); j++){
                
                cnt[words[i][j] - 'a']++;
                if(cnt[words[i][j] - 'a'] == 2){
                    pairs++;
                    cnt[words[i][j] - 'a'] = 0;
                }
                
            }
        }
        vector<int> segs; 
        for(int i = 0; i < words.size(); i++){
            segs.push_back(words[i].size() / 2);
        }
        
        sort(segs.begin(), segs.end());
        
        int res = 0;
        for(int s : segs){
            if(pairs - s >= 0){
                res++;
                pairs = pairs - s;
            }
        }
        
        return res;
    }
};