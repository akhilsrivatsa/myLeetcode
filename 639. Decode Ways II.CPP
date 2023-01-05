class Solution {
public:
    vector<int> dp;
    int helper(string &s, int index){

        int mod = pow(10, 9) + 7;

        if(index == s.length()){
            return 1;
        }

        if(dp[index] != -1) return dp[index];
        
        if(s[index] == '0') return 0;

        

        int ans = 0;
        if(s[index] == '*'){

            for(int i = 1 ; i <= 9; i++){
                 ans = (ans + helper(s, index + 1) % mod)  % mod;
            }

            if(index != s.length() - 1 && s[index + 1] >= '0' &&  s[index + 1] <= '6'){
               
                   ans = (ans + helper(s, index + 2) % mod)  % mod;
               
            }

            if(index != s.length() - 1 && s[index + 1] >= '0' &&  s[index + 1] <= '9'){
               
                   ans = (ans + helper(s, index + 2) % mod)  % mod;
               
            }

             if(index != s.length() - 1 && s[index + 1] == '*'){
               for(int k = 1; k <= 2; k++){
                   int limit = 0;
                   if(k == 1) limit = 9;
                   else limit = 6;
                   for(int p = 1; p <= limit; p++){
                        ans = (ans + helper(s, index + 2) % mod)  % mod;
                   }
               }
            }
        }else{

                if(s[index] < '3'){
                    
                    if(index != s.length() - 1 && s[index] == '2' &&  s[index + 1] >= '0' &&  s[index + 1] <= '6'){
                         ans = (ans + helper(s, index + 2) % mod)  % mod;
                    }

                     if(index != s.length() - 1 && s[index] == '1' &&  s[index + 1] >= '0' &&  s[index + 1] <= '9'){
                         ans = (ans + helper(s, index + 2) % mod)  % mod;
                    }

                    if(index != s.length() - 1 && s[index + 1] == '*'){
                       
                       
                        if(s[index] == '2'){
                             
                            for(int p = 1; p <= 6; p++){
                                 ans = (ans + helper(s, index + 2) % mod)  % mod;
                            }
                        }
                       
                        if(s[index] == '1'){
                            
                            for(int p = 1; p <= 9; p++){
                                 ans = (ans + helper(s, index + 2) % mod)  % mod;
                            }
                        }

                    }
                        
                }
                  ans = (ans + helper(s, index + 1)  % mod) ;
            }

              
                return dp[index] = ans % mod ;
    }
    int numDecodings(string s) {

        dp.resize(s.length(), -1);
        return helper(s, 0) % 1000000007;
        
    }
};