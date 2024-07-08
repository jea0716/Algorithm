#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, answer;
vector <int> v(3, 0);

int dp[61][61][61];

int solution(int x, int y, int z) {
    if(x < 0) return solution(0, y, z);
    if(y < 0) return solution(x, 0, z);
    if(z < 0) return solution(x, y, 0);

    if(x == 0 && y == 0 && z == 0) return 0;

    int res = dp[x][y][z];

    if(res != -1) return res;
    res = 1e9;
    res = min(res, solution(x - 9, y - 3, z - 1) + 1);
    res = min(res, solution(x - 9, y - 1, z - 3) + 1);
    res = min(res, solution(x - 3, y - 9, z - 1) + 1);
    res = min(res, solution(x - 3, y - 1, z - 9) + 1);
    res = min(res, solution(x - 1, y - 3, z - 9) + 1);
    res = min(res, solution(x - 1, y - 9, z - 3) + 1);

    dp[x][y][z] = res;
    return res;
}

int main() {
    cin >> N;

    for(int i=0; i<N; i++) { 
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solution(v[0], v[1], v[2]) << '\n';

    return 0;
}