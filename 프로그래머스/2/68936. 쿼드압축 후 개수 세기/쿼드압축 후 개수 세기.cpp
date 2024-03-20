#include <string>
#include <vector>

using namespace std;

int one, zero;
vector<vector<int>> v;

bool check(int n, int x, int y) {
    int color = v[x][y];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(v[i+x][j+y] != color) return false;
        }
    }
    
    return true;
}

void solve(int n, int x, int y) {
    if(n == 0) return ;
    if(check(n, x, y)) {
        if(v[x][y] == 0) zero++;
        else one++;
        
        return;
    }
    
    int half = n / 2;
    solve(half, x, y);
    solve(half, x + half, y);
    solve(half, x, y + half);
    solve(half, x + half, y + half);
    
    return ;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    v = arr;
    solve(arr.size(), 0, 0);
    
    answer[0] = zero;
    answer[1] = one;
    return answer;
}