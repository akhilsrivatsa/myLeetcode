class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        vector<int> ans(nums1.size());
        unordered_map<int, int> dp;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i]){
               st.pop();
           }
           if(st.empty()){
               dp[nums2[i]] = -1;
           }else{
               dp[nums2[i]] = st.top();
           }
           st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            ans[i] = dp[nums1[i]];
        }
        return ans;


        
    }
};