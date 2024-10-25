#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
long long a, b;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> a >> b;
        cout << (a / b) * (a / b) << '\n';
    }

    return 0;
}   