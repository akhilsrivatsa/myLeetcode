class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {

        int mx = 0;
        vector<vector<int>> matrix(mat.size(), vector<int> (mat[0].size()));
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size() ; j++){
                matrix[i][j] = mat[i][j] - '0';
                cout<<matrix[i][j]<<endl;
            }
        }


        for(int i = 0; i < matrix.size(); i++ ){
            for(int j = 0; j < matrix[i].size() ; j++){
                    if(matrix[i][j] == 1){
                    
                    int left = (j - 1 >= 0) ? matrix[i][j - 1] : 0;
                    int deleft = ((j - 1 >= 0) && i - 1 >= 0) ? matrix[i - 1][j - 1] : 0;
                    int up = ( i - 1 >= 0) ?  matrix[i - 1][j] : 0;
                    matrix[i][j] = min(left, min(up, deleft)) + 1;
                    int p = matrix[i][j];
                    mx = max(mx , p);
                 }
             }
        }
        return mx * mx;
        
    }
};