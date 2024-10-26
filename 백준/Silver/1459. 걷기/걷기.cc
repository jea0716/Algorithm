#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long  X, Y, A, B;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> X >> Y >> A >> B;

    long long case1 = (X + Y) * A;
    long long case2 = min(X, Y) * B;
    case2 += min(abs(X - Y) * A, abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * B + A : abs(X - Y) * B);

    cout << min(case1, case2) << '\n';

    return 0;
}   