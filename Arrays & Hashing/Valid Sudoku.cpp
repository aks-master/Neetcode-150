/*

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num = board[i][j];
                if (num != '.')
                {
                    string rowKey = string(1, num) + " in row " + to_string(i);
                    string colKey = string(1, num) + " in col " + to_string(j);
                    string boxKey = string(1, num) += " in box " + to_string(i / 3) + "-" + to_string(j / 3);
                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey))
                    {
                        return false;
                    }
                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }
        return true;
    }
};