#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;

set<string> answer;
int arr[5][5];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void solve(int a, int b) {
    queue<pair<string, pair<int, int>>> q;
    q.push({ to_string(arr[a][b]), { a, b } });

    while(!q.empty()) {
        string num = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(num.length() == 6) {
            answer.insert(num);
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= 5) continue;
            if(ny < 0 || ny >= 5) continue;

            q.push({ num + to_string(arr[nx][ny]), { nx, ny } });
        }
    }
}

int main() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) cin >> arr[i][j];
    }

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) solve(i, j);
    }

    cout << answer.size() << endl;

    return 0;
}