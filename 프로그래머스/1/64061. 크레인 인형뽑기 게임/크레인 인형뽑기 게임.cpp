#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> basket;

void move(int n) {
    bool check = true;
    for(int i=0; i<v.size(); i++) {
        if(v[i][n] != 0 && check) {
            basket.push_back(v[i][n]);
            v[i][n] = 0;
            check = false;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    v = board;
    for(int i=0; i<moves.size(); i++) {
        move(moves[i] - 1);
        if(basket.size() > 1 && 
           basket[basket.size()-1] == basket[basket.size()-2]
          ) {
            basket.pop_back();
            basket.pop_back();
            answer += 2;
        }
    }
    
    return answer;
}