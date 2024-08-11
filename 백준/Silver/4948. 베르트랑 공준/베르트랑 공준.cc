#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool arr[250000];

int print(int n) {
    int cnt = 0;

    for(int i=n+1; i<=2*n; i++) {
        if(!arr[i]) cnt++;
    }

    return cnt;
}

void solve() {
    for(int i=2; i<250000; i++) {
        for(int j=i+i; j<250000; j=j+i) {
            arr[j] = 1;
        }
    }

    return ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    solve();
    int N; cin >> N;

    while(N != 0) {
        cout << print(N) << '\n';
        cin >> N;
    }

    return 0;
}