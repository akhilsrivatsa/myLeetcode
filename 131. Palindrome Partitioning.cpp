class Solution {
public:
  bool isPalind(string s){
      int st = 0;
      int end = s.length() - 1;
      while(st < end && s[st] == s[end]){
          st++;
          end--;
      }

      return st >= end;
  }

   void helper(string s, vector<string>&temp, vector<vector<string>> &ans){

      if(s == ""){
          ans.push_back(temp);
          return;
      } 
      for(int i = 0; i < s.length(); i++){

           if(isPalind(s.substr(0, i + 1))){

               temp.push_back(s.substr(0, i + 1));
               helper(s.substr(i + 1, s.length() - i), temp, ans);
               temp.pop_back();
           }


       }





    }
    vector<vector<string>> partition(string s) {
        
        
        vector<vector<string>> ans;
        vector<string> temp;
        helper(s, temp, ans);
        return ans;


    }
};