#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, tmp;
vector<int> v;
vector<int> ans(2, 0);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int s = 0, e = N - 1, min = 2000000001;

    while(s < e) {
        if(abs(v[s] + v[e]) < min) {
            ans[0] = v[s]; 
            ans[1] = v[e]; 
            min = abs(v[s] + v[e]);
        }

        if(v[s] + v[e] < 0) s++;
        else e--;
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << ans[1] << '\n';

    return 0;
}