class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int cap){

        int sum = 0;
        int currDay = 1;
        for(int i = 0; i < weights.size(); i++){

            if(weights[i] > cap){
                return false;
            }

            sum+= weights[i];

            if(sum > cap){
                sum = weights[i];
                currDay++;
            }
            if(currDay > days){
                return false;
            }
        }
        

        return true;

    }
    int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
           sum += weights[i]; 
        }

        int low = 1, high = sum;
        int minPoss = INT_MAX;

        while(low <= high){

            int mid = (low + (high - low) / 2);
            
            if(isPossible(weights, days, mid)){
                high = mid - 1;
                minPoss = mid;
            }else{
                low = mid + 1;
            }
        }

        return minPoss;
    }
};