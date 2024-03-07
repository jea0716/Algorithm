#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    for(int i=0; i<keyinput.size(); i++) {
        if(keyinput[i] == "up" && answer[1] < (board[1] / 2)) answer[1] += 1;
        else if(keyinput[i] == "down" && answer[1] > -(board[1] / 2)) answer[1] -= 1;
        else if(keyinput[i] == "left" && answer[0] > -(board[0] / 2)) answer[0] -= 1;
        else if(keyinput[i] == "right" && answer[0] < (board[0] / 2)) answer[0] += 1;
    }
    return answer;
}