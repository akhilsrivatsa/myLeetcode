class Solution {
public:
  bool isFinshedNeeds(vector<int> &needs){

         for(int i = 0; i < needs.size(); i++){
            if(needs[i] > 0) return false;
        }
        return true;

    }
    int dfs(vector<int> &price, vector<vector<int>> &special, vector<int> needs,  map<vector<int>, int> &cache){


       if(isFinshedNeeds(needs)){
            return 0;
        }
        if(cache[needs] != 0) return cache[needs];

        int withSpecial = INT_MAX;
        int notWithSpecial = 0;
        for(int i = 0; i < special.size(); i++){
            vector<int> temp = needs;
            bool canBeApplied = true;
            int k;
            for(k = 0; k < needs.size(); k++){
                if(temp[k] - special[i][k] < 0){
                    canBeApplied = false;
                    break;
                }
                temp[k] -= special[i][k];
            }

            if(canBeApplied) withSpecial = min(withSpecial, special[i][k] + dfs(price, special, temp, cache));
         }
         
        for(int i = 0; i < needs.size(); i++){
             notWithSpecial += needs[i] * price[i];
        }
        cout << withSpecial << " " << notWithSpecial;
        return cache[needs] = min(withSpecial, notWithSpecial);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        map<vector<int>, int> cache;
        return dfs(price, special, needs, cache);
        
    }
};