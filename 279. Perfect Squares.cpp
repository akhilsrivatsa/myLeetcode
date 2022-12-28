class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n + 1, INT_MAX);
        vector<int> squares(n +1);
        set<int> s;
        

        for(int i = 1; i * i <= n; i++){

            s.insert(i * i);
        }
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){

          for(auto itr : s){
              if(itr <= i) dp[i] = min(dp[i], 1 + dp[i - itr]);
              else break;
          }
        }

        return dp[n];
        
    }
};