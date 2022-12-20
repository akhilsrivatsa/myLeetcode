class Solution {
public:

    int decode(string s , int i, vector<int> &dp){

        if(i == s.length()){
            return 1;
        }

        if(dp[i] != 0) return dp[i];

        if(s[i] == '0') return 0;
        int one_char = decode(s, i + 1, dp);

        string two_string = s.substr(i , 2);
        int two_string_int = i == s.length() - 1 ?  27 : stoi(two_string);

        int two_char = 0;
        if(two_string_int <= 26 ){
            two_char = decode(s, i + 2, dp);
        }

        return dp[i] = one_char + two_char;
    }


    int numDecodings(string s) {
        
        vector<int> dp(s.length());
        return decode(s, 0, dp);
    }
};