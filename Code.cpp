#include <iostream>
#include <vector>

using namespace std;


bool found = false;

bool validCell(vector<vector<int>>& board, int row, int col, int n){
    if (row >= 0 && row < n && col >= 0 && col < n && board[row][col] == 0){
        return true;
    }
    else
        return false;
}


void KnightsTour(vector<vector<int>>& board, int startRow, int startCol, int count, int n, int moveX[], int moveY[]){
    
    if (found)
    return;

    if (count == n*n+1){
        cout << "Knight's Tour found!" << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << board[i][j] << "    ";
            }
            cout << endl;
        }
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++){
        int newRow = startRow + moveX[i];
        int newCol = startCol + moveY[i];
        if (validCell(board, newRow, newCol, n)){
            board[newRow][newCol] = count;
            KnightsTour(board, newRow, newCol, count + 1, n, moveX, moveY);
            board[newRow][newCol] = 0; // backtrack
        }
    }
    return;
}


int main(){

    cout << "Enter the size of the chessboard: ";
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if(n < 5 && n != 1)
    cout << "No solution exists for boards of size " << n << endl;
    else
    cout << "Enter the starting position of the knight (row and column): " << endl;
    int startRow, startCol;
    cin >> startRow >> startCol;
    if (startRow < 0 || startRow >= n || startCol < 0 || startCol >= n){
        cout << "Invalid starting position!" << endl;
        return 0;
    }
    board[startRow][startCol] = 1;
    int moveX[8] = {2,1,-1,-2,-2,-1, 1, 2};
    int moveY[8] = {1,2, 2, 1,-1,-2,-2,-1};
    
    
    KnightsTour(board, startRow, startCol, 2, n, moveX, moveY);

}
