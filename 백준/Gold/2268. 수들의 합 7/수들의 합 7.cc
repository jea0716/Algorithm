#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

ll N, M;
ll A, B, C;

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
        if(i == start && i == end) {
            tree[node] = diff;
            return ;
        }

        if(start != end) {
            update(node * 2, start, mid, i, diff);
            update(node * 2 + 1, mid + 1, end, i, diff);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    Seg se(N);
    se.init(1, 1, N);

    for(int i=0; i<M; i++) {
        cin >> A >> B >> C;

        if(A == 0) {
            if(B < C) cout << se.sum(1, 1, N, B, C) << '\n';
            else cout << se.sum(1, 1, N, C, B) << '\n';
        }
        else {
            se.update(1, 1, N, B, C);
            se.seq[B] = C;
        }
    }

    return 0;
}