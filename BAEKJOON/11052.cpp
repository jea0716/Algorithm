#include <iostream>

using namespace std;

//1-1 2-11,2 3-111,21,3 4-1111,112,22,13,4 5-11111,1112,113,14,122,23,5
//6-111111,11112,1113,114,15,6,1122,222,33

int dp[1001];

int main(){
    int n; cin >> n;
    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    int temp;
    for(int i=2; i<=n; i++){
        if(i==2) dp[2] = max(arr[1] * 2, arr[2]);
        else{
            temp = arr[i];
            for(int j=i; j>0; j--){
                if(temp < dp[j-1] + dp[i-j+1]) temp = dp[j-1] + dp[i-j+1];
            }
            dp[i] = temp;
        }
    }
    cout << dp[n] << endl;
    return 0;
}