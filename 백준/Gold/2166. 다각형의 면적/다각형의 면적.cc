#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N; cin >> N;

    vector<pair<long long, long long>>v;

    long long x, y;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    long long num1 = 0, num2 = 0, answer = 0;

    v.push_back({ v[0].first, v[0].second });

    for(int i=0; i<N; i++) {
        num1 += v[i].first * v[i+1].second;
    }

    for(int i=0; i<N; i++) {
        num2 += v[i+1].first * v[i].second;
    }

    answer = abs(num1 - num2);

    if(answer % 2 == 0) cout << answer / 2 << ".0\n";
    else cout << answer / 2 << ".5\n";

    return 0;
}