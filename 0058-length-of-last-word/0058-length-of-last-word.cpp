class Solution {
public:
    int lengthOfLastWord(string s) {
        
        
        bool hasSeenLetter = false;
        int len = 0;
        
        for(int i = s.length() - 1; i >= 0; i--){
            
            if(hasSeenLetter && s[i] == ' ') return len;
            
            if(s[i] == ' ') continue;
            
            hasSeenLetter = true;
            len++;
            
            
        }
        
        return len;
    }
};