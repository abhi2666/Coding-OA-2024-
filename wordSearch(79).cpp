// My Code - not running all the test cases

// class Solution
// {
// private:
//     bool dfs(int r, int c, int idx, string &word, vector<vector<char>> &board)
//     {
//         for(int i = 0; i < board.size(); i++){
//             for(int j = 0; j < board[0].size(); j++) {
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         // if you have processed the whole string
//         if (idx == word.size())
//         {
//             // means you got the word
//             return true;
//         }
//         int rows = board.size();
//         int cols = board[0].size();
//         // check all the directions and move whereever you find the next character
//         int dr[] = {-1, 1, 0, 0};
//         int dc[] = {0, 0, -1, 1};
//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = r + dr[i];
//             int ncol = c + dc[i];
//             if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && board[nrow][ncol] == word[idx])
//             {
//                 char temp = board[nrow][ncol];
//                 // first mark that word so that we don't pick it again
//                 board[nrow][ncol] = '.'; // we can use a visited matrix also
//                 if (dfs(nrow, ncol, idx + 1, word, board))
//                     return true;
//                 // after dfs is done we will remove the marking we did
//                 board[nrow][ncol] = temp;
//             }
//         }
//         return false;
//     }

// public:
//     bool exist(vector<vector<char>> &board, string word)
//     {
//         // traverse the whole matrix and look for the very first character of it
//         for (int i = 0; i < board.size(); i++)
//         {
//             for (int j = 0; j < board[0].size(); j++)
//             {
//                 if (board[i][j] == word[0])
//                 {
//                     // apply dfs from here and try to use dfs to form the whole string
//                     if (dfs(i, j, 1, word, board))
//                     {
//                         return true;
//                     }
//                     else
//                     {
//                         continue;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

//chatgpt code
class Solution {
private:
    bool dfs(int r, int c, int idx, string &word, vector<vector<char>>& board) {
        // if you have processed the whole string
        if (idx == word.size()) {
            // means you got the word
            return true;
        }
        
        // Store the original character and mark it so as to not pick it --> Test case - [['a', 'a']]
        char original = board[r][c];
        // Mark the current cell as visited
        board[r][c] = '.'; // You can also use a visited matrix instead
        
        // check all the directions and move wherever you find the next character
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if (nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && board[nrow][ncol] == word[idx]) {
                if (dfs(nrow, ncol, idx + 1, word, board)) {
                    return true;
                }
            }
        }
        
        // Restore the original character
        board[r][c] = original;
        
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        // traverse the whole matrix and look for the very first character of it
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    // apply dfs and look for the word to create
                    if (dfs(i, j, 1, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
