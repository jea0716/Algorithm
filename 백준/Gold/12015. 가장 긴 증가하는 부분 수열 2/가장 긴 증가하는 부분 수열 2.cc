#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int arr[1000001], dp[1000001];
vector<int> sequence;

void bi_search(int n) {
    int low = 0, high = sequence.size()-1, mid;
    int ret = 987654321;

    while(low <= high) {
        mid = (low + high) / 2;
        int cur_num = sequence[mid];
        if(cur_num >= n) {
            if(ret > mid) ret = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    sequence[ret] = n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    sequence.push_back(arr[0]);

    for(int i=1; i<N; i++) {
        if(sequence.back() < arr[i]) {
            sequence.push_back(arr[i]);
        }
        else {
            bi_search(arr[i]);
        }
    }

    cout << sequence.size() << '\n';

    return 0;
}