class Solution {
public:
    bool parseBoolExpr(string expression) {


        stack<char> op;
        stack<char> st;

        string s = expression;


        for(int i = 0; i < expression.length(); i++){

             //cout <<" index " << i << endl;

            if(s[i] == '&' || s[i] == '!' || s[i] == '|'){
                op.push(s[i]);
                continue;
            }

            if(s[i] != ')'){
                if(s[i] != ',')st.push(s[i]);
                continue;
            }
           
            char oper = op.top();
            op.pop();
            bool found = false;
            bool currVal; 

           
            while(st.top() != '('){

              //  cout << "Here" << endl;

                bool cv  = (st.top() == 'f') ? false : true;
                st.pop();

                if(!found){
                    
                    currVal = cv;
                    if(oper == '!'){
                        currVal = !cv;
                    }
                    found = true;
                    continue;
                }
                 cout << oper << endl;
                
                if(oper == '&'){
                    currVal = currVal and cv;
                }else if(oper == '|'){
                     currVal = currVal or cv;
                }else{
                   // cout << "Performing not " << endl;
                    currVal = !(cv);
                }
            }
            st.pop();
            char ch;
            //cout << "curr : " << currVal << endl;
            if(currVal){
                ch = 't';
            }else{
                ch = 'f';
            }
          
            st.push(ch);
        }



        return st.top() == 't';
        
    }
};