#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int go, int to) {
    if(n == 1) {
        answer.push_back({ go, to });
        return ;
    }
    
    hanoi(n - 1, go, 6 - go - to);
    hanoi(1, go, to);
    hanoi(n - 1, 6 - go - to, to);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3);
    
    return answer;
}