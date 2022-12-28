class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {


        int sum = 0;

        for(int i = 0; i < matrix.size(); i++){

            for(int j = 0; j < matrix[i].size(); j++){


                if(matrix[i][j] == 1){


                   int diagonal = (i == 0 || j == 0) ? 0 : matrix[i - 1][j - 1]; 
                   int up = (i == 0) ? 0 : matrix[i - 1][j] ;
                   int left = (j == 0) ? 0 : matrix[i][j - 1];

                   matrix[i][j] = 1 + min(diagonal, min(up, left));

                   cout << matrix[i][j] << " ";
                   sum = sum + matrix[i][j];
                  
                }else {

                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
        return sum;
        
    }
};