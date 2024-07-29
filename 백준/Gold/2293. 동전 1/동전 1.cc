#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int N, K, tmp;
vector<int> v;
int dp[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    dp[0] = 1;

    for(int i=0; i<v.size(); i++) {
        for(int j=v[i]; j<=K; j++) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[K] << '\n';

    return 0;
}