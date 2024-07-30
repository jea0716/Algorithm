#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
using ll = long long;

vector<ll> seq;
vector<ll> tree;
vector<ll> lazy;

int N, M, K;

void init(ll node, ll start, ll end) {
    ll mid = (start + end) / 2;

    if(start == end) tree[node] = seq[start];
    else {
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update_lazy(ll node, ll start, ll end) {
    if(lazy[node]) {
        tree[node] += (lazy[node] * (end - start + 1));
        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll sum(ll node, ll start, ll end, ll i, ll j) {
    update_lazy(node, start, end);
    ll mid = (start + end) / 2;

    if(i > end || j < start) return 0;
    if(i <= start && j >= end) return tree[node];
    return sum(node * 2, start, mid, i, j) + sum(node * 2 + 1, mid + 1, end, i, j);
}

void update(ll node, ll start, ll end, ll i, ll j, ll diff) {
    update_lazy(node, start, end);
    ll mid = (start + end) / 2;

    if(i > end || j < start) return;
    if(i <= start && j >= end) {
        tree[node] += (diff * (end - start + 1));
        if(start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return ;
    }

    update(node * 2, start, mid, i, j, diff);
    update(node * 2 + 1, mid + 1, end, i, j, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> K;

    ll height = ceil(log2(N));
    ll size = (1 << (height + 1));
    tree.resize(size);
    lazy.resize(size);
    seq.resize(N + 1);

    for(int i=1; i<=N; i++) cin >> seq[i];

    init(1, 1, N);

    int cnt = M + K;

    ll A, B, C, D;
    while(cnt--) {
        cin >> A;
        if(A == 1) {
            cin >> B >> C >> D;
            update(1, 1, N, B, C, D);
        }
        else {
            cin >> B >> C;
            cout << sum(1, 1, N, B, C) << '\n';
        }
    }

    return 0;
}