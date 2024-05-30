#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v[32001];
vector<int> cnt(32001, 0);
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> N >> M;

    int A, B;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        cnt[B]++;
        v[A].push_back(B);
    }

    for(int i=1; i<=N; i++) {
        if(cnt[i] == 0) pq.push(i);
    }

    while(!pq.empty()) {
        int n = pq.top();
        pq.pop();

        cout << n << " ";

        for(int i=0; i<v[n].size(); i++) {
            int nn = v[n][i];
            cnt[nn]--;
            if(cnt[nn] == 0) pq.push(nn);
        }
    }

    cout << '\n';

    return 0;
}