class Solution {
public:
    bool detectCapitalUse(string word) {

        int capitals = 0;
        int small = 0;
        int k = -1;
        int index = k;
        for(char ch : word){
            k++;
            if(isupper(ch)){
                capitals++;
                index = k;
            }else{
                small++;
            }
        }

        if(capitals == word.size() || small == word.size()) return true;
        if(capitals == 1) return index == 0;
        return false;
        
    }
};