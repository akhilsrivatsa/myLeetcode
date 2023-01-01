class Solution {
public:
    int minimumPartition(string s, int k) {


        long cs = 0;
        int subCount = 0;
        for(int i = 0 ; i < s.length(); i++){

            cs = cs * 10 + s[i] - '0';
            if(cs > k){
                cs = s[i] - '0';
                if(cs > k) return -1;
                subCount++;
            }


        }
        subCount++;
        return subCount > 0 ? subCount : -1;
        
    }
};