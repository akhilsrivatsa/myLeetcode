class Solution {
public:

    int max_sum = 0;

    int dfs(vector<int> &arr, int k, int index, vector<int> &dp){

        if(index == arr.size()){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int maxEle = arr[index];
        int ck = 1;
        int cs = 0;

        for(int i = index; i < arr.size() &&  i < index + k ; i++){

            maxEle = max(maxEle, arr[i]);
            cs = max( cs, dfs(arr, k, i + 1, dp) + (maxEle * ck));
            ck++;

        }

        return dp[index] = cs;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

      
       vector<int> dp(arr.size(), -1);
       return dfs(arr, k, 0, dp);
       
        
    }
};