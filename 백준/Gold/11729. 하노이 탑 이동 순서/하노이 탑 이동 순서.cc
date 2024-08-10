#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(int n, int start, int to, int by) {
    if(n == 1) cout << start << " " << to << '\n';
    else {
        solve(n - 1, start, by, to);
        cout << start << " " << to << '\n';
        solve(n - 1, by, to, start);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin >> N;

    cout << (1 << N) - 1 << '\n';
    solve(N, 1, 3, 2);

    return 0;
}