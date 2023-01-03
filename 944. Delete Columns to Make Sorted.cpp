class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del = 0;
        int k = 0;
        for(k = 0; k < strs[0].size(); k++){


            for(int i = 1; i < strs.size(); i++){

                if(strs[i][k] < strs[i - 1][k]){
                    del++;
                    break;
                }
            }
        }
        return del;
        
    }
};