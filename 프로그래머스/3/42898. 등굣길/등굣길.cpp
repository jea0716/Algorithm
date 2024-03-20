#include <string>
#include <vector>

using namespace std;

int N = 1000000007;

int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) map[i][j] = -1;
    }
    for(int i=0; i<puddles.size(); i++) {
        map[puddles[i][0]][puddles[i][1]] = 0;
    }
    map[1][1] = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j] == -1) {
                map[i][j] = ((map[i-1][j] % N) + (map[i][j-1] % N)) % N;
            }
        }
    }
    answer = map[m][n];
    return answer;
}