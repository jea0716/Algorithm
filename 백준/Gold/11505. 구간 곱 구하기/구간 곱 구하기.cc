#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
#define MOD 1000000007

struct Seg {
    vector<ll> tree;
    vector<ll> seq;

    Seg(ll N) {
        ll height = ceil(log2(N));
        ll size = (1 << (height + 1));
        tree.resize(size);
        seq.resize(N + 1);
    }

    void init(ll node, ll start, ll end) {
        ll mid = (start + end) / 2;

        if(start == end) tree[node] = seq[start];
        else {
            init(node * 2, start, mid);
            init(node * 2 + 1, mid + 1, end);
            tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
        }
    }

    ll mul(ll node, ll start, ll end, ll i, ll j) {
        ll mid = (start + end) / 2;
        if(i > end || j < start) return 1;
        if(i <= start && j >= end) return tree[node];
        return (mul(node * 2, start, mid, i, j) * mul(node * 2 + 1, mid + 1, end, i, j)) % MOD;
    }

    void update(ll node, ll start, ll end, ll i, ll diff) {
        ll mid = (start + end) / 2;
        if(i < start || i > end) return ;
        if(start == i && end == i) {
            tree[node] = diff;
            return ;
        }
        if(start != end) {
            update(node * 2, start, mid, i, diff);
            update(node * 2 + 1, mid + 1, end, i, diff);
        }
        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
    }
};

ll N, M, K;
ll A, B, C;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;

    Seg se(N);
    for(int i=1; i<=N; i++) cin >> se.seq[i];

    se.init(1, 1, N);
    ll cnt = M + K;
    while(cnt--) {
        cin >> A >> B >> C;
        if(A == 1) {
            se.update(1, 1, N, B, C);
            se.seq[B] = C;
        }
        else cout << se.mul(1, 1, N, B, C) << '\n';
    }


    return 0;
}