class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){

        if(a[1] < b[1]) return true;

        if(a[1] == b[1]){
            return a[0] < b[0];
        }

        return false;

    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int minArrows = 1;
        sort(points.begin(), points.end(), comp);
        int maxRight = points[0][1];
        for(int i = 1; i < points.size(); i++){

            if(maxRight >= points[i][0]){
                continue;
            }
            minArrows++;
            maxRight = points[i][1];
        }
        return minArrows;
    }
};