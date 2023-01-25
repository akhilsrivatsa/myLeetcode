class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        stack<int> num;
       

        for(int i = 0; i < s.size(); i++){

            int cn = 0;
            while(s[i] >= '0' && s[i] <= '9'){
                cn = (cn * 10) + (s[i] - '0'); 
                i++;
            }
            if(cn > 0){
                num.push(cn);
            }

            if(s[i] != ']'){
                st.push(s[i]);
                continue;
            }

            string temp = "";

            while(st.top() != '['){

                temp = temp + st.top();
                st.pop();

            }
            st.pop();
            reverse(temp.begin(), temp.end());
            int freq;
            
            if(num.empty()){
                freq = 1;
            }else{
                freq = num.top();
                num.pop();
            }
            string temp1 = "";
            for(int k = 0; k < freq; k++){
                temp1 = temp1 + temp;
            }

            for(char ch : temp1){
                st.push(ch);
            }
           
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};