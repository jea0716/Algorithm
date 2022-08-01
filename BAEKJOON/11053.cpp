#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n], temp, count, answer=0;
    int dp[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
                cout << dp[i] << " ";
            }
        }
        cout << endl;
    }
    for(int i=0; i<n; i++){
        if(dp[i] > answer) answer = dp[i];
    }

    cout << answer << "\n";

    return 0;
}