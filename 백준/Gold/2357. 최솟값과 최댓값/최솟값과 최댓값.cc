#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

ll N, M, A, B;
vector<ll> tree_max;
vector<ll> tree_min;
vector<ll> seq;

void init_max(int node, int start, int end) {
    ll mid = (start + end) / 2;

    if(start == end) {
        tree_max[node] = seq[start];
    }
    else {
        init_max(node * 2, start, mid);
        init_max(node * 2 + 1, mid + 1, end);
        tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]);
    }
}

ll find_max(ll node, ll start, ll end, ll i, ll j) {
    ll mid = (start + end) / 2;

    if(i > end || j < start) return 0;
    if(i <= start && j >= end) return tree_max[node];

    return max(find_max(node * 2, start, mid, i, j), find_max(node * 2 + 1, mid + 1, end, i, j));
}

void init_min(int node, int start, int end) {
    ll mid = (start + end) / 2;

    if(start == end) {
        tree_min[node] = seq[start];
    }
    else {
        init_min(node * 2, start, mid);
        init_min(node * 2 + 1, mid + 1, end);
        tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
    }
}

ll find_min(ll node, ll start, ll end, ll i, ll j) {
    ll mid = (start + end) / 2;

    if(i > end || j < start) return 1e9;
    if(i <= start && j >= end) return tree_min[node];

    return min(find_min(node * 2, start, mid, i, j), find_min(node * 2 + 1, mid + 1, end, i, j));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    ll height = ceil(log2(N));
    ll size = (1 << (height + 1));
    tree_max.resize(size);
    tree_min.resize(size);
    seq.resize(N + 1);

    for(int i=1; i<=N; i++) cin >> seq[i];
    init_max(1, 1, N);
    init_min(1, 1, N);

    while(M--) {
        cin >> A >> B;
        cout << find_min(1, 1, N, A, B) << " " << find_max(1, 1, N, A, B) << '\n';
    }

    return 0;
}