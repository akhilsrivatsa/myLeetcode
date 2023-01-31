class Solution {
public:
    // 8.08

    /*

        [{1, 5}, {1, 5}, {2, 4}, {2, 6}]


        [5, 5, 4, 4]

        [5, 10, 4, 16]

    */
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        vector<pair<int, int>> v(scores.size());
        vector<int> dp(scores.size());
      

        for(int i = 0; i < scores.size(); i++){
            v[i] = make_pair(ages[i], scores[i]);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < dp.size(); i++){
            dp[i] = v[i].second;
        }

          int maxScore = dp[0];

        for(int i = 1; i < dp.size(); i++){

            for(int j = 0; j < i ; j++){
                
                if(v[i].second >= v[j].second || v[i].first == v[j].first){
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                    maxScore = max(dp[i], maxScore);

                } 
            }
        }

        return maxScore;
        
    }
};