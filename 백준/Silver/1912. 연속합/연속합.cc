#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, answer;
int dp[100001], arr[100001];

int main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    dp[0] = arr[0];
    answer = arr[0];
    for(int i=1; i<N; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        answer = dp[i] > answer ? dp[i] : answer;
    }

    cout << answer << endl;

    return 0;
}