#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    int temp, count = 0;

    for(int i=0; i<n; i++) cin >> arr[i];
    int answer[301];
    answer[0] = arr[0];
    answer[1] = arr[0] +arr[1];
    answer[2] = max(arr[0], arr[1]) + arr[2];

    for(int i=3; i<n; i++){
        answer[i] = max((answer[i-3] + arr[i-1]), answer[i-2]) + arr[i];
    }

    cout << answer[n-1] << endl;

    return 0;
}
