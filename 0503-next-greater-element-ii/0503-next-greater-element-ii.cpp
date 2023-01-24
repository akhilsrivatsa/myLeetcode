class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int index = -1;
        int maxEle = INT_MIN;
        for(int i = 0; i <  nums.size(); i++){
            if(nums[i] > maxEle){
                maxEle = nums[i];
                index = i;
            }
        }
        vector<int> dp(nums.size(), -1);
        stack<int> st;
        int j = index;
        bool first = true;
        while(true){
            
            if(index < 0){
                index = nums.size() - 1;
            }

            if(j == index && !first){
                break;
            }

            
            while(!st.empty() && st.top() <= nums[index]){
                st.pop();
            }
            if(st.empty()){
                dp[index] = -1;
            }else{
                dp[index] = st.top();
            }

            st.push(nums[index]);
            index--;
            first = false;
        }

        return dp;
        
    }
};