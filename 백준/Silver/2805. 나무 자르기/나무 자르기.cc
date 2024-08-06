#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, tmp;
long long sum;
vector <int> v;

void solve() {
    int l = 0, r = v[N-1];

    while(l <= r) {
        int mid = (l + r) / 2;
        sum = 0;

        for(int i=0; i<N; i++) {
            sum += v[i] - mid > 0 ? v[i] - mid : 0;
        }

        if(sum >= M) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    solve();

    return 0;
}