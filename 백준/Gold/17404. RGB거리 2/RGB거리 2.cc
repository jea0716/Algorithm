#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, answer = INF;
int arr[1001][3];
int dp[1001][3];

int main() {
    cin >> N;
    
    int R, G, B;
    for(int i=1; i<=N; i++) {
        cin >> R >> G >> B;
        arr[i][0] = R;
        arr[i][1] = G;
        arr[i][2] = B;
    }

    dp[1][0] = arr[1][0];
	dp[1][1] = dp[1][2] = INF;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	answer = min(answer, min(dp[N][1], dp[N][2]));

    dp[1][1] = arr[1][1];
	dp[1][0] = dp[1][2] = INF;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	answer = min(answer, min(dp[N][0], dp[N][2]));
    
	dp[1][2] = arr[1][2];
	dp[1][0] = dp[1][1] = INF;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	answer = min(answer, min(dp[N][0], dp[N][1]));

	cout << answer << '\n';

    return 0;
}