class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        

        queue<int> q;
        int ans = 0, st = 0, end = 0, count = 0, lastOccur = -1;
        int prevIndex;
        while(end < nums.size()){
            if(nums[end] % 2){
                q.push(end);
                prevIndex = lastOccur;
                lastOccur = end;
                count++;
            }
            if(count > k){
                
                ans = ans + (q.front() - st + 1) * (end - prevIndex);
                
                while(count > k){
                    if(nums[st] % 2){
                        count--;
                        q.pop();
                    }
                    st++;
                }
            }
            end++;
        }
       if(q.size() > 0 && count == k) ans = ans + (q.front() - st + 1) * (end - lastOccur);
        return ans;
    }
};