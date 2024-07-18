#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, t;
vector<int> v;
vector<int> ans(2, 0);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> t;
        v.push_back(t);
    }

    int s = 0, e = N - 1, min = 2000000001;

    sort(v.begin(), v.end());

    while(s < e) {
        int sum = v[s] + v[e];

        if(abs(sum) < min) {
            ans[0] = v[s];
            ans[1] = v[e];
            min = abs(sum);
        }

        if(sum < 0) s++;
        else e--;
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << ans[1] << '\n';

    return 0;
}