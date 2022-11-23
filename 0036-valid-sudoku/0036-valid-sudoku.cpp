class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>>cols;   
        unordered_map<int,unordered_set<int>>rows;
        map<pair<int,int>,unordered_set<int>>square;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(rows[i].find(board[i][j]-'0')!=rows[i].end() || 
                   cols[j].find(board[i][j]-'0')!=cols[j].end() ||
                   square[{i/3,j/3}].find(board[i][j]-'0')!=square[{i/3,j/3}].end()){
                    return false;
                }
                rows[i].insert(board[i][j]-'0');
                cols[j].insert(board[i][j]-'0');
                square[{i/3,j/3}].insert(board[i][j]-'0');
            }    
        }
        return true;
    }
};