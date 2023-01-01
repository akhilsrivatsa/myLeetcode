class Solution {
public:
/*
1) "NYNNYYYN"
*/


    int bestClosingTime(string customers) {

        vector<int> yCount(customers.size(), 0);
        int minPenalty = INT_MAX;
        int count = 0;
        int nCount = 0;
        int minHour = -1;

        for(int i = customers.size() - 1; i >= 0; i--){
            if(customers[i] == 'Y') count++;
            yCount[i] = count;
        }
        if(yCount[0] == customers.size()) return yCount[0];
        
        for(int i = 0; i < customers.size(); i++){
                if(minPenalty > yCount[i] + nCount){
                    minPenalty = yCount[i] + nCount;
                    minHour = i;
                }
                if(customers[i] == 'N') nCount++;
        }

        if(nCount < minPenalty){
            minHour = customers.size();
        }
        return minHour;
    }
};