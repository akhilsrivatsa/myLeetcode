class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        if(prerequisites.size() == 0) return true;


        queue<int> q;
        vector<int> pre(numCourses);
        int allVisitedCourses = 0;
        for(int i = 0; i < prerequisites.size(); i++){
            pre[prerequisites[i][0]]++;
        }

        for(int i = 0; i < pre.size(); i++){

            if(pre[i] == 0){
                q.push(i);
                allVisitedCourses++;
            }
        }

        while(!q.empty()){

            int x = q.front();
            cout<<x<<endl;
            q.pop();

            for(int i = 0; i < prerequisites.size(); i++){


                    if(prerequisites[i][1] == x){

                         pre[prerequisites[i][0]]--;

                         if( pre[prerequisites[i][0]] == 0){
                             q.push(prerequisites[i][0]);
                             allVisitedCourses++;
                             if(allVisitedCourses == numCourses) return true;
                         }
                    }


            }




        }

        return false;



    }
};