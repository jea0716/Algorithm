#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, tmp;
long long answer;
int set[1001];
vector<vector<int>> v;

int getParent(int n) {
    if(set[n] == n) return n;
    return set[n] = getParent(set[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++) set[i] = i;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> tmp;
            if(i == j) continue;
            if(i < j && i != j) v.push_back({ tmp, i, j });
        }
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        int s = getParent(v[i][1]);
        int e = getParent(v[i][2]);
        int cost = v[i][0];

        if(s != e) {
            answer += cost;
            set[s] = e;
        }
    }

    cout << answer << '\n';

    return 0;
}   