#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    if(h-1 >= 0 && board[h-1][w] == board[h][w]) answer++;
    if(h+1 < board.size() && board[h+1][w] == board[h][w]) answer++;
    if(w-1 >= 0 && board[h][w-1] == board[h][w]) answer++;
    if(w+1 < board.size() && board[h][w+1] == board[h][w]) answer++;
    return answer;
}