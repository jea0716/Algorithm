#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

int N, x, y;
vector<pair<int, int>> v;
int dp[101];

bool cmp(const pair<int, int>& n1, const pair<int, int>& n2) {
    if(n1.first == n2.first) return n1.second < n2.second;
    return n1.first < n2.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;

    v.push_back({ 0, 0 });
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        if(x < y) v.push_back({ x, y });
        else v.push_back({ y, x });
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=1; i<=N; i++) {
        for(int j=0; j<i; j++) {
            if(v[i].first >= v[j].first && v[i].second >= v[j].second) {
                dp[i] = dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i];
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=N; i++) answer = answer > dp[i] ? answer : dp[i];
    cout << answer << '\n';

    return 0;
}