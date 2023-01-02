class Solution {
public:

    int isPalindrome(string s, int l, int r,map<string, int>& cache){

        if(!cache[s]) return cache[s];
        int a = 0;
         while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
            a++;
            
        }
        return cache[s] = a;
    }
    int countSubstrings(string s) {

        int ans = 0;
        map<string, int> cache;
        for(int i = 0; i < s.size(); i++){
            int p = isPalindrome(s, i - 1, i, cache ) + isPalindrome(s, i - 1, i + 1, cache) + 1;
            ans+=p;
        }
        return ans;
        
    }
};