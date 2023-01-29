class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {


        int sr = 0, er = matrix.size() - 1;
        int sc = 0, ec = matrix[0].size() - 1;
        vector<int> ans;
        int  k = 0;

        while(sr <= er && sc <= ec){


            for(int i = sc; i <= ec; i++){
                ans.push_back(matrix[sr][i]);
                cout <<  matrix[sr][i] << endl;
            }
            sr++;

            if(sr == er){
               // break;
            }

            for(int i = sr ; i <= er ; i++){
                ans.push_back(matrix[i][ec]);
                cout << matrix[i][ec] << endl;
            }
            ec--;

            if(ec == sc){
               // break;
            }

            for(int i = ec ; i >= sc && sr <= er; i--){

                ans.push_back(matrix[er][i]);
                 cout <<  matrix[er][i] << endl;
            }

            if(er == sr){
              //  break;
            }

            er--;

            for(int i = er; i >= sr && sc <= ec ; i--){
                ans.push_back(matrix[i][sc]);
                cout <<matrix[i][sc] << endl;
            }
            
            sc++;
        }

        return ans;
        
    }
};