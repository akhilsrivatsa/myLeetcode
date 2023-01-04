class Solution {
public:
    vector<int> countBits(int n) {
        

        vector<int> ans(n + 1);
        int index = 0;

        for(int i = 0; i <= n; i++){

           int count = 0;
           int p = i;
            while(p > 0){
                if(p & 1){
                    count++;
                }
                p = p >> 1;
            }
            ans[index++]= count;
        }

        return ans;
    }
};