class Solution {
public:

    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<int> v;
        for(int i = 0 ; i < dist.size(); i++){

            int time = (dist[i] / speed[i]);
            if(dist[i] % speed[i]) time++;
            v.push_back(time);
        }
        sort(v.begin(), v.end());

        int time = 0;
        int monsters = 0;

        for(int i = 0; i < v.size(); i++){

            if(v[i] - time <= 0){
                break;
            }
            time++;
            monsters++;

        }

        return monsters;
        
    }
};