class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        int current = 0;
        int ans = 0;
        vector<int> dp(s.length(), 0);
        for(int i = 0; i < s.length(); i++){

           
            if(s[i] == '('){
                st.push(i);
               
            }
            else if(s[i] == ')' && st.empty()){
                
            }else{
                int in = st.top();
                st.pop();
              
                dp[in] = 1;
                dp[i] = 1;
                
            }
        }


        for(int i = 0; i < dp.size(); i++){

            if(dp[i] == 1){
                current++;
            }else{
                current = 0;
            }

            ans = max(ans, current);
        }
        return ans;
        
    }
};