#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, answer = 1;
int arr[1001];
int dp_max[1001], dp_min[1001];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

    dp_max[1] = 1;
    for(int i=2; i<=N; i++) {
        int cnt = 0;
        for(int j=1; j<i; j++) {
            if(arr[i] > arr[j]) {
                if(dp_max[j] > cnt) cnt = dp_max[j];
            }
        }
        dp_max[i] = cnt + 1;
    }

    for(int i=N; i>0; i--) {
        int cnt = 0;
        for(int j=N; j>i; j--) {
            if(arr[i] > arr[j]) {
                if(dp_min[j] > cnt) cnt = dp_min[j];
            }
        }
        dp_min[i] = cnt + 1;
    }

    for(int i=1; i<=N; i++) {
        answer = answer > dp_max[i] + dp_min[i] - 1 ? answer : dp_max[i] + dp_min[i] - 1;
    }

    cout << answer << endl;

    return 0;
}