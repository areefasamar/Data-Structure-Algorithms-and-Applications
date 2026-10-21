// Areefa Samar - CT-25062
// Question 04 (Lab 04)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool searchWord(vector<vector<char>>& board, string word, int row, int col, int idx) {
    
    if (idx == word.length())
        return true;

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()
        || board[row][col] != word[idx])
        return false;

    char temp = board[row][col];
    board[row][col] = '*'; 

    bool found = searchWord(board, word, row + 1, col, idx + 1) ||
                 searchWord(board, word, row - 1, col, idx + 1) ||
                 searchWord(board, word, row, col + 1, idx + 1) ||
                 searchWord(board, word, row, col - 1, idx + 1);

    board[row][col] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (searchWord(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word1 = "ABCCED";
    string word2 = "ABCB";

    cout << word1 << ": " << (exist(board, word1) ? "true" : "false") << endl;
    cout << word2 << ": " << (exist(board, word2) ? "true" : "false") << endl;

    return 0;
}