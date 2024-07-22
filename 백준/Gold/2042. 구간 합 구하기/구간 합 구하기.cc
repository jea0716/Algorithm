#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

struct Seg {
    vector <ll> tree;
    vector <ll> seq;

    Seg(ll N) {
        seq.resize(N + 1);
        ll height = ceil(log2(N));
        ll size = (1 << (height + 1));
        tree.resize(size);
    }

    void init(ll node, ll start, ll end) {
        ll mid = (start + end) / 2;

        if(start == end) tree[node] = seq[start];
        else {
            init(node * 2, start, mid);
            init(node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    ll sum(ll node, ll start, ll end, ll i, ll j) {
        ll mid = (start + end) / 2;
        if(i > end || j < start) return 0;
        if(i <= start && j >= end) return tree[node];
        return sum(node * 2, start, mid, i, j) + sum(node * 2 + 1, mid + 1, end, i, j);
    }

    void update(ll node, ll start, ll end, ll i, ll diff) {
        ll mid = (start + end) / 2;
        if(i < start || i > end) return;
        tree[node] += diff;
        if(start != end) {
            update(node * 2, start, mid, i, diff);
            update(node * 2 + 1, mid + 1, end, i, diff);
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll N, M, K;
    ll a, b, c;
    cin >> N >> M >> K;

    Seg se(N);
    for(int i=1; i<=N; i++) {
        cin >> se.seq[i];
    }

    se.init(1, 1, N);
    ll cnt = M + K;
    while(cnt--) {
        cin >> a >> b >> c;
        if(a == 1) {
            se.update(1, 1, N, b, c - se.seq[b]);
            se.seq[b] = c;
        }
        else cout << se.sum(1, 1, N, b, c) << '\n';
    }

    return 0;
}