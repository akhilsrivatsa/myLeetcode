class Solution {
public:
    vector<int> ans;
    bool found = false;
    void findAnswer(string num, int ind){
        if(ind == num.size()){
          if(ans.size() > 2)found = true;
            return;
        }

        string temp = "";

        for(int i = ind; i < num.size(); i++){

            if(ind == i - 1 && num[ind] == '0'){
                //cout << "Here " << endl;
                return;
            }

            temp = temp + num[i];
            long long curr = stol(temp);
            if(curr >= pow(2, 31)){
               return;
            }
            if(ans.size() < 2){
                ans.push_back(curr);
                findAnswer(num, i + 1);
                if(found) return;
                ans.pop_back();
            }else{
                long long v1 = ans[ans.size() - 2];
                long long v2 = ans[ans.size() -  1];

                if(v1 + v2 == curr){
                    ans.push_back(curr);
                    findAnswer(num, i + 1);
                    if(found) return;
                    ans.pop_back();
                }

                if(v1 + v2 < curr){
                    return;
                }

            }

            
        }

        return;
    }
    vector<int> splitIntoFibonacci(string num) {
        
        findAnswer(num, 0);
        return ans;
        
    }
};