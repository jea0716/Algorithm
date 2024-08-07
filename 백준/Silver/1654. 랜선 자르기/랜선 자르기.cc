#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, tmp;
long long sum;
vector<int> v;

int main() {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    long long left = 1, right = v[N - 1], mid;

    while(left <= right) {
        int sum = 0;
        mid = (left + right) / 2;
        for(int i=0; i<N; i++) sum += v[i] / mid;

        if(sum >= M) left = mid + 1;
        else right = mid - 1;
    }

    cout << right << '\n';

    return 0;
}