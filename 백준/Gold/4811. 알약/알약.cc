#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N;
long long dp[31][31];

long long solve(int w, int h) {
    if(h == -1) return 0;
    if(w == 0) return 1;

    long long &ret = dp[w][h];
    if(ret) return dp[w][h];

    ret = solve(w - 1, h + 1) + solve(w, h - 1);

    return ret;
}

int main() {

    while(1) {
        cin >> N;
        if(N == 0) return 0;
        
        cout << solve(N, 0) << '\n';
    }

    return 0;
}