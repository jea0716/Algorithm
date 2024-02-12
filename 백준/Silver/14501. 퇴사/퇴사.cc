#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int day, value;
};

int N;
node arr[16];
int answer[16];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i].day >> arr[i].value;

    for(int i=N; i > 0; i--) {
        if(arr[i].day + i - 1 > N) answer[i] = answer[i+1];
        else {
            answer[i] = max(answer[i+1], answer[arr[i].day + i] + arr[i].value);
        }
    }

    cout << answer[1] << endl;

    return 0;
}