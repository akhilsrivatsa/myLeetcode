class Solution {
public:
    bool isPalindrome(int x) {

        string res = to_string(x);
        int l = 0, hi = res.size() - 1;

        while(l  <= hi){

            if(res[l] != res[hi]) return false;
            l++;
            hi--;

        }

        return true;
        
    }
};