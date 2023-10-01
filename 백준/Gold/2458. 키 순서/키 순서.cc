#include <iostream>
#include <vector>

using namespace std;

int map[501][501];
int MAX = 999999999;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) continue;
            map[i][j] = MAX;
        }
    }

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        map[a][b] = 1;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(map[i][j] > map[i][k] + map[k][j]) map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=n; i++) {
        int test = 1;
        for(int j=1; j<=n; j++) {
            if(map[i][j] == MAX && map[j][i] == MAX) test = 0;
        }
        answer += test;
    }

    cout << answer << "\n";

    return 0;
}