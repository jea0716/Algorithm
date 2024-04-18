#include <string>
#include <vector>

using namespace std;

vector <int> board(12, 0);
int answer;

bool isAble(int idx, int cnt) {
    for(int i=0; i<cnt; i++) {
        if(board[i] == idx) return false;
        if(abs(board[i]-idx) == abs(cnt - i)) return false;
    }
    return true;
}

void DFS(int cnt, int n) {
    if(cnt == n) {
        answer++;
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(isAble(i, cnt)) {
            board[cnt] = i;
            DFS(cnt + 1, n);
        }
    }
}

int solution(int n) {
    DFS(0, n);
    return answer;
}