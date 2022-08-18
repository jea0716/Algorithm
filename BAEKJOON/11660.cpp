#include <iostream>

using namespace std;

int dp[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m; cin >> n >> m;
    int arr[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    } 
    int x1, y1, x2, y2, answer;
    for(int i=0; i<m; i++){
        answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        answer = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        cout << answer << '\n';
    }
    return 0;
}