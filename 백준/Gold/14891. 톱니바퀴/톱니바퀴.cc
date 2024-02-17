#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int> > wheel(4);
char input[100];
bool wheel_move[4];
int N, num, direction, answer;

void move(int n, int dir) {
    if(dir == 1) {
        int tmp = wheel[n][7];
        for(int i=6; i>=0; i--) wheel[n][i+1] = wheel[n][i];
        wheel[n][0] = tmp;
    }
    else {
        int tmp = wheel[n][0];
        for(int i=1; i<8; i++) wheel[n][i-1] = wheel[n][i];
        wheel[n][7] = tmp;
    }
}

void solve(int n, int dir) {
    if(wheel_move[n] == true) return;

    if(n > 0 && n < 3) {
        wheel_move[n] = true;
        if(wheel[n][6] != wheel[n-1][2] && wheel_move[n-1] == false) solve(n-1, (-1)*dir);
        if(wheel[n][2] != wheel[n+1][6] && wheel_move[n+1] == false) solve(n+1, (-1)*dir);
        move(n, dir);
    }
    else if(n == 0) {
        wheel_move[n] = true;
        if(wheel[n][2] != wheel[n+1][6] && wheel_move[n+1] == false) solve(n+1, (-1)*dir);
        move(n, dir);
    }
    else if(n == 3) {
        wheel_move[n] = true;
        if(wheel[n][6] != wheel[n-1][2] && wheel_move[n-1] == false) solve(n-1, (-1)*dir);
        move(n, dir);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    for(int i=0; i<4; i++) {
        cin >> input;
        for(int j=0; j<8; j++) wheel[i].push_back(input[j] - '0');
    }

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> num >> direction;
        for(int j=0; j<4; j++) wheel_move[j] = false;
        solve(num - 1, direction);
    }

    for(int i=0; i<4; i++) {
        if(wheel[i][0] == 1) {
            if(i == 0) answer += 1;
            if(i == 1) answer += 2;
            if(i == 2) answer += 4;
            if(i == 3) answer += 8;
        }
    }

    cout << answer << "\n";
}