class Solution {
public:
    bool isPossible(vector<int>& time, int totalTrips, long long int possibleTime){


        long long currentTrips = 0;

        for(int i = 0; i < time.size(); i++){

            currentTrips +=  (possibleTime / time[i]);
            if(currentTrips > totalTrips){
                return true;
            }
        }
        return currentTrips == totalTrips;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
       // sort(time.begin(), time.end());
        long long  low = 1; 
        long long  high = ((long long)time[0] * totalTrips);
        long long  ans = high;

        while(low <= high){

            long long mid = low + (high - low) / 2;
            if( isPossible(time, totalTrips, mid)){
                high = mid - 1;
                ans = mid; 
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};