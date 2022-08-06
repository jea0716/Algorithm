#include <iostream>

using namespace std;


//6 10 13 9 8 1
//6 16 23 28 33

int dp[10001];

int main(){
    int n; cin >> n;
    int arr[n], answer = 0;

    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++){
        if(i == 0) dp[0] = arr[0];
        else if(i == 1) dp[1] = arr[0] + arr[1];
        else if(i == 2) dp[2] = max(dp[1], arr[2] + max(arr[0], arr[1]));
        else{
            dp[i] = max(dp[i-1], arr[i] + max(dp[i-3] + arr[i-1], dp[i-2]));
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}