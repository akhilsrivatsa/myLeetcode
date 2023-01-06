class Solution {

 /*
        1, 1, 2, 3, 5, 6 coins = 20

 */   
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int sum = 0;

        for(int i = 0; i < costs.size(); i++){

            if(sum + costs[i] <= coins){
                sum =  sum + costs[i];
            }else{
                return i;
            }
        }



        return sum == 0 ? 0 : costs.size();
        
    }
};