class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

         vector<int> ans; 
        if(prerequisites.size() == 0){

            for(int i = 0; i < numCourses; i++) ans.push_back(i);
            return ans;
        }


        queue<int> q;
       
        vector<int> pre(numCourses);
        int allVisitedCourses = 0;
        for(int i = 0; i < prerequisites.size(); i++){
            pre[prerequisites[i][0]]++;
        }

        for(int i = 0; i < pre.size(); i++){

            if(pre[i] == 0){
                q.push(i);
                 ans.push_back(i);
              allVisitedCourses++;
            }
        }

        while(!q.empty()){

            int x = q.front();
           
            q.pop();

            for(int i = 0; i < prerequisites.size(); i++){


                    if(prerequisites[i][1] == x){

                         pre[prerequisites[i][0]]--;

                         if( pre[prerequisites[i][0]] == 0){
                             q.push(prerequisites[i][0]);
                               ans.push_back(prerequisites[i][0]);
                             allVisitedCourses++;
                             if(allVisitedCourses == numCourses) return ans;
                         }
                    }


            }




        }
        ans = {};

        return ans;
        
    }
};