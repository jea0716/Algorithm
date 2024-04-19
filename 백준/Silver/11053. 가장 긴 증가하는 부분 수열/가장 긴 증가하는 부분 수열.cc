#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];
int answer = 1;

int main() {
    int N; cin >> N;

    for(int i=1; i<=N; i++) cin >> arr[i];

    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        int cnt = 0;
        for(int j=1; j<i; j++) {
            if(arr[i] > arr[j]) {
                if(dp[j] > cnt) cnt = dp[j];
            }
        }
        dp[i] = cnt + 1;
        answer = answer > dp[i] ? answer : dp[i];
    }

    cout << answer << endl;

    return 0;
}