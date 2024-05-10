#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int map[16][16];
int dp[16][16][3];

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    dp[0][1][0] = 1;
    for(int i=2; i<N; i++) {
        if(map[0][i] == 0) dp[0][i][0] = dp[0][i-1][0];
    }

    for(int i=1; i<N; i++) {
        for(int j=2; j<N; j++) {
            if(map[i][j] == 0) {
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
                dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];
                if(map[i-1][j] == 0 && map[i][j-1] == 0) {
                    dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
                }
            }
        }
    }

    cout << dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2] << endl;

    return 0;
}