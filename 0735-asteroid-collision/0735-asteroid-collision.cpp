class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        vector<int> ans;
        for(int i = 0; i < asteroids.size(); i++){

            int curr = asteroids[i];

            if(curr > 0){
                st.push(curr);
            }else{
               bool found = false;
               while(!st.empty()){

                   if(st.top() < 0){
                       found = false;
                       break;
                   }
                   if(st.top() > abs(curr)){
                       found = true;
                       break;
                   }
                   if(st.top() == abs(curr)){
                       st.pop();
                       found = true;
                       break;
                   }
                   st.pop();
               }
              if(!found){
                  st.push(curr);
              }
          }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};