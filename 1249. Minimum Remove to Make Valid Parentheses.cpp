class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack< int> st;
        set<int> useless;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' ) st.push(i);

            if(s[i] == ')'){
                 

                 if(st.size() == 0){
                     useless.insert(i);
                     continue;
                 }
                 if(s[st.top()]  == '(' ) st.pop();
            }

           
            
        }

        while(!st.empty()){
            useless.insert(st.top());
            st.pop();
        }


        string res;

        for(int i = 0; i < s.length(); i++){

            if(useless.count(i) == 0) res.push_back(s[i]);
        }
 
        return res;
        
    }
};