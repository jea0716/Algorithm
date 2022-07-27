#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    const int m = n;
    int arr[m][3];
    int answer = 0;

    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int i=1; i<n; i++){
        arr[i][0] += min(arr[i-1][1], arr[i-1][2]);
        arr[i][1] += min(arr[i-1][0], arr[i-1][2]);
        arr[i][2] += min(arr[i-1][0], arr[i-1][1]);
    }

    answer = min(arr[n-1][0], arr[n-1][1]);
    answer = min(answer, arr[n-1][2]);

    cout << answer << endl;

    return 0;
}