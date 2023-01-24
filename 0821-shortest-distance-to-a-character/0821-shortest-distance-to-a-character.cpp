class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        vector<int> ans(s.size());

        for(int i = 0; i < s.size(); i++){

            if(s[i] == c){
                ans[i] = 0;
                continue;
            }

            int left = i - 1; 
            int right = i + 1;
            int res = 0;

            while(true){

                if(left >= 0 && s[left] == c){
                    res = abs(left - i);
                    break;
                }
                 if(right < s.size() && s[right] == c){
                    res = abs(right - i);
                    break;
                }
                left--;
                right++;
            }
            ans[i] = res;

        }

        return ans;
        
    }
};