#include <iostream>

using namespace std;

int dp_up[100001];
int dp_down[100001];

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int max_num = 1;

    dp_up[0] = dp_down[0] = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] >= arr[i-1]) {
            dp_up[i] = dp_up[i-1] + 1;
            if (dp_up[i] > max_num) max_num = dp_up[i];
        }
        else {
            dp_up[i] = 1;
        }
    }

    for(int i=1; i<n; i++) {
        if(arr[i] <= arr[i-1]) {
            dp_down[i] = dp_down[i-1] + 1;
            if (dp_down[i] > max_num) max_num = dp_down[i];
        }
        else {
            dp_down[i] = 1;
        }
    }


    cout << max_num << "\n";
    return 0;
}