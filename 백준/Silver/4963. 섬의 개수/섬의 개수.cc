#include <iostream>

using namespace std;

int map[52][52];
int visited[52][52];
int W, H;

int col[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int row[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int n, int m) {
    visited[n][m] = 1;
    
    for(int i=0; i<8; i++) {
        if(map[n+col[i]][m+row[i]] == 1 && visited[n+col[i]][m+row[i]] == 0) {
            bfs(n+col[i], m+row[i]);
        } 
    }

    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> W >> H;

    while(W != 0 && H != 0) {
        for(int i=1; i<=H; i++) {
            for(int j=1; j<=W; j++) {
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }

        int answer = 0;

        for(int i=1; i<=H; i++) {
            for(int j=1; j<=W; j++) {
                if(map[i][j] == 1 && visited[i][j] == 0) {
                    answer++;
                    bfs(i, j);
                }
            }
        }

        cout << answer << "\n";

        cin >> W >> H;
    }

    return 0;
}