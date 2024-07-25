#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

ll N, M, A, B;
vector<ll> tree;
vector<ll> seq;

void init(int node, int start, int end) {
    ll mid = (start + end) / 2;

    if(start == end) {
        tree[node] = seq[start];
    }
    else {
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

ll find(ll node, ll start, ll end, ll i, ll j) {
    ll mid = (start + end) / 2;

    if(i > end || j < start) return 1e9;
    if(i <= start && j >= end) return tree[node];

    return min(find(node * 2, start, mid, i, j), find(node * 2 + 1, mid + 1, end, i, j));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    ll height = ceil(log2(N));
    ll size = (1 << (height + 1));
    tree.resize(size);
    seq.resize(N + 1);

    for(int i=1; i<=N; i++) cin >> seq[i];
    init(1, 1, N);

    while(M--) {
        cin >> A >> B;
        cout << find(1, 1, N, A, B) << '\n';
    }

    return 0;
}