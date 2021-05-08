class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int mask[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
        vector<int>rowMask(9), colMask(9), tblMask(9);
        
        int tblIdx = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << "i: " << i << " j: " << j << " tbl: " << tblIdx << endl;
                if(board[i][j] != '.') {
                int val = board[i][j] - '0' - 1;
                if(rowMask[i] & mask[val]) return false;
                if(colMask[j] & mask[val]) return false;
                if(tblMask[tblIdx] & mask[val]) return false;
                rowMask[i] |= mask[val];
                colMask[j] |= mask[val];
                tblMask[tblIdx] |= mask[val];
                }
                if(j%3 == 2) tblIdx++;
            }
            if(i%3 != 2) tblIdx -= 3;
        }
        return true;
    }
};
