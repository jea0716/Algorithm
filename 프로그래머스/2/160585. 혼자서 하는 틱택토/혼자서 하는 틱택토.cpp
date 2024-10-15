#include <string>
#include <vector>
#include <iostream>

using namespace std;

int O = 0, X = 0;

void check(vector<string> board)
{
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].length(); j++)
        {
            if(board[i][j] == 'X') X++;
            else if(board[i][j] == 'O') O++;
        }
    }
    
    return ;
}

bool checkO(vector<string> board) {
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
        return true;
    if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
        return true;
    if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
        return true;
    if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
        return true;
    if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
        return true;
    if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
        return true;
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        return true;
    if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
        return true;
    
    return false;
}

bool checkX(vector<string> board) {
    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
        return true;
    if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
        return true;
    if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
        return true;
    if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
        return true;
    if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
        return true;
    if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
        return true;
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        return true;
    if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
        return true;
    
    return false;
}

int solution(vector<string> board) {
    check(board);
    cout << X << " " << O << endl;
    if(X > O) return 0;
    if(abs(X - O) > 1) return 0;
    
    if(checkO(board) && O <= X) return 0;
    if(checkX(board) && O != X) return 0;
    
    return 1;
}