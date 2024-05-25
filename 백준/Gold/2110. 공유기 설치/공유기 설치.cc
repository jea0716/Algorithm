#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C, num, start, end, mid, ans = 0;
    vector<int> v;

    cin >> N >> C;
    for(int i=0; i<N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    start = 0;
    end = v[N-1] - v[0];

    while(start <= end) {
        int router = 1;
        mid = (start + end) / 2;
        int st = v[0];

        for(int i=1; i<N; i++) {
            if(v[i] - st  >= mid) {
                router++;
                st = v[i];
            }
        }

        if(router >= C) {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}