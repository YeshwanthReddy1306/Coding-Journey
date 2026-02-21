class Solution {
public:
    
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    int box = (r / 3) * 3 + (c / 3);
                    
                    rows[r][num] = true;
                    cols[c][num] = true;
                    boxes[box][num] = true;
                }
            }
        }
        
        backtrack(board);
    }
    
    bool backtrack(vector<vector<char>>& board) {
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                
                if (board[r][c] == '.') {
                    
                    int box = (r / 3) * 3 + (c / 3);
                    
                    for (int num = 0; num < 9; num++) {
                        
                        if (!rows[r][num] && !cols[c][num] && !boxes[box][num]) {
                            // Place number
                            board[r][c] = num + '1';
                            rows[r][num] = true;
                            cols[c][num] = true;
                            boxes[box][num] = true;         
                            if (backtrack(board))
                                return true;
                            board[r][c] = '.';
                            rows[r][num] = false;
                            cols[c][num] = false;
                            boxes[box][num] = false;
                        }
                    }
                    return false;
                }
            }
        }  
        return true;
    }
};