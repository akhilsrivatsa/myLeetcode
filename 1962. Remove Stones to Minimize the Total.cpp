class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {


        priority_queue<int> pq;
        int s = 0;

        for(int pile : piles){
            pq.push(pile);
        }

        while(k){

            int ele = pq.top();
            pq.pop();
            pq.push(ele - ele / 2);
            k--;
        }

        while(!pq.empty()){

            s += pq.top();
            pq.pop();

        }

        return s;


        
    }
};