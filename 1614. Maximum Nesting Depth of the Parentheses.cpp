class Solution {
public:
    int maxDepth(string s) {

        stack<char> st;

        int maxDepth = 0;
        int currDepth = 0;
        for(int i = 0; i < s.length(); i++){

            if(s[i] == '('){

                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            }
            if(s[i] == ')'){
                currDepth--;
            }



        }

        return maxDepth;
        
    }
};