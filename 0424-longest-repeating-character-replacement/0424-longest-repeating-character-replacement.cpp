class Solution {
public:

/*
s = "AABABBA" K = 1
*/

    int getMaxCount(vector<int> &count){
        
        int maxCount = 0;
        for(int i = 0; i < 26; i++){
            maxCount = max(maxCount, count[i]);
        }
        return maxCount;
    }
    int characterReplacement(string s, int k) {


        vector<int> count(26, 0);
        int st = 0, end = 0;
        int maxLen = 0;
        
        while(end < s.size()){

            count[s[end] - 'A']++;
            while((end - st + 1) - getMaxCount(count) > k){
                count[s[st] - 'A']--;
                st++;
            }
            maxLen = max(maxLen, end - st + 1);
            end++;
        }

        return maxLen;
        
    }
};