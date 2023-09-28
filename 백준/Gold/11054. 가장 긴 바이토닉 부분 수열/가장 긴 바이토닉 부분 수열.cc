#include <iostream>

using namespace std;

int dp_up[1001];
int dp_down[1001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp_up[j] >= dp_up[i]) {
                dp_up[i] = dp_up[j] + 1;
            }
        }   
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=n-1; j>=i; j--) {
            if(arr[i] > arr[j] && dp_down[j] >= dp_down[i]) {
                dp_down[i] = dp_down[j] + 1;
            }
        }
    }

    int answer = 0;

    for(int i=0; i<n; i++) {
        if(answer < dp_up[i] + dp_down[i] + 1) {
            answer = dp_up[i] + dp_down[i] + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}