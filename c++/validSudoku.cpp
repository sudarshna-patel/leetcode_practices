// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); i++) {
            unordered_map<char, bool> row;
            unordered_map<char, bool> col;
            unordered_map<char, bool> cube;

            for (int j = 0; j < board[i].size(); j++) {
                
                if (board[i][j] != '.')
                    if (col.find(board[i][j]) != col.end())
                        return false;
                    else
                        col.insert({board[i][j], true});
                
                if (board[j][i] != '.')
                    if (row.find(board[j][i]) != row.end())
                        return false;
                    else
                        row.insert({board[j][i], true});
                
                int RowIndex = 3*(i/3);
                int ColIndex = 3*(i%3);
                if(board[RowIndex + j/3][ColIndex + j%3] != '.')
                    if (cube.find(board[RowIndex + j/3][ColIndex + j%3]) != cube.end())
                        return false;
                    else
                        cube.insert({board[RowIndex + j/3][ColIndex + j%3], true});
            }
        }

        return true;
    }
};